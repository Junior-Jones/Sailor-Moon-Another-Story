#include "sailor_moon_apu13.h"
#include <limits.h>
#include <stddef.h>
#include <string.h>

/* Architectural IPL ROM, not cartridge payload or a captured APU image. */
static const uint8_t sm12_rom[64] = {
    0xCD,0xEF,0xBD,0xE8,0x00,0xC6,0x1D,0xD0,0xFC,0x8F,0xAA,0xF4,0x8F,0xBB,0xF5,0x78,
    0xCC,0xF4,0xD0,0xFB,0x2F,0x19,0xEB,0xF4,0xD0,0xFC,0x7E,0xF4,0xD0,0x0B,0xE4,0xF5,
    0xCB,0xF4,0xD7,0x00,0xFC,0xD0,0xF3,0xAB,0x01,0x10,0xEF,0x7E,0xF4,0x10,0xEB,0xBA,
    0xF6,0xDA,0x00,0xBA,0xF4,0xC4,0xF4,0xDD,0x5D,0xD0,0xDB,0x1F,0x00,0x00,0xC0,0xFF
};

static int sm12_attached(const Sm12Apu *a) {
    return a != NULL && a->bus != NULL && a->scheduler != NULL && a->scheduler->bus == a->bus;
}

static Sm08Status sm12_fault(Sm12Apu *a, Sm08Status status, unsigned owner,
                            uint16_t address, Sm08Value sample) {
    a->phase = SM12_FAILED;
    return sm08_bus_fault(a->bus, status, owner, address, sample);
}

static Sm08Status sm12_known(Sm12Apu *a, uint16_t address, Sm08Value v, uint8_t *out) {
    if (v.known_mask != 0xFFu) return sm12_fault(a, SM08_UNKNOWN, 12u, address, v);
    *out = v.value;
    return SM08_OK;
}

static uint16_t sm12_dp(const Sm12Apu *a, uint8_t offset) {
    return (uint16_t)(((a->ipl.psw & 0x20u) != 0u ? 0x100u : 0u) + offset);
}

static void sm12_nz(Sm12Apu *a, uint8_t value) {
    a->ipl.psw = (uint8_t)((a->ipl.psw & 0x7Du) | (value & 0x80u) |
                           (value == 0u ? 2u : 0u));
}

static void sm12_nz16(Sm12Apu *a, uint16_t value) {
    a->ipl.psw = (uint8_t)((a->ipl.psw & 0x7Du) | ((value >> 8) & 0x80u) |
                           (value == 0u ? 2u : 0u));
}

static void sm12_compare(Sm12Apu *a, uint8_t left, uint8_t right) {
    a->ipl.psw = (uint8_t)((a->ipl.psw & 0xFEu) | (left >= right ? 1u : 0u));
    sm12_nz(a, (uint8_t)(left - right));
}

static void sm12_clear_inputs(Sm12Apu *a, uint8_t first) {
    uint8_t i;
    for (i = first; i < (uint8_t)(first + 2u); ++i) {
        a->cpu_input[i] = (Sm08Value){0u, 0xFFu};
        a->pending_input[i] = (Sm08Value){0u, 0xFFu};
        a->visible_sequence[i] = 0u;
        a->pending_sequence[i] = 0u;
        a->pending_mask &= (uint8_t)~(1u << i);
    }
}

static void sm12_control(Sm12Apu *a, uint8_t value) {
    uint8_t i;
    for (i = 0u; i < 3u; ++i) {
        uint8_t enable = (uint8_t)((value >> i) & 1u);
        if (enable != 0u && a->timers[i].enabled == 0u) {
            a->timers[i].stage = 0u;
            a->timers[i].output = 0u;
        }
        a->timers[i].enabled = enable;
    }
    if ((value & 0x10u) != 0u) sm12_clear_inputs(a, 0u);
    if ((value & 0x20u) != 0u) sm12_clear_inputs(a, 2u);
    a->control = value;
    a->ipl_enabled = (uint8_t)(value >> 7);
}

Sm08Status sm12_apu_smp_read(Sm12Apu *a, uint16_t address, Sm08Value *out) {
    if (!sm12_attached(a) || out == NULL) return SM08_ARGUMENT;
    if (a->bus->fault.status != SM08_OK) return a->bus->fault.status;
    if (address >= 0xFFC0u && a->ipl_enabled != 0u) {
        *out = (Sm08Value){sm12_rom[address - 0xFFC0u], 0xFFu};
    } else if (address >= 0xF0u && address <= 0xFFu) {
        if (address == 0xF2u) *out = (Sm08Value){a->dsp_address, 0xFFu};
        else if (address == 0xF3u) {
            Sm08Status status;
            if (a->dsp.read == NULL) return sm12_fault(a, SM08_REGISTER, 16u, address, (Sm08Value){0u,0u});
            status=a->dsp.read(a->dsp.context, (uint8_t)(a->dsp_address & 0x7Fu), out);
            return status==SM08_OK ? status : sm12_fault(a,status,16u,address,(Sm08Value){0u,0u});
        } else if (address >= 0xF4u && address <= 0xF7u) {
            uint8_t p = (uint8_t)(address - 0xF4u);
            *out = a->cpu_input[p];
            a->sampled_sequence[p] = a->visible_sequence[p];
            a->sampled_half[p] = a->completed_half + 2u;
        } else if (address == 0xF8u || address == 0xF9u) *out = a->aux[address - 0xF8u];
        else if (address >= 0xFDu) {
            uint8_t t = (uint8_t)(address - 0xFDu);
            *out = (Sm08Value){a->timers[t].output, 0xFFu};
            a->timers[t].output = 0u;
        } else *out = (Sm08Value){0u, 0xFFu};
    } else *out = a->aram[address];
    return SM08_OK;
}

Sm08Status sm12_apu_smp_write(Sm12Apu *a, uint16_t address, Sm08Value value) {
    uint8_t byte = 0u;
    Sm08Status status;
    if (!sm12_attached(a)) return SM08_ARGUMENT;
    if (a->bus->fault.status != SM08_OK) return a->bus->fault.status;
    if (a->phase==SM12_STATIC_RUNNING) {
        if(a->static_owner.before_write==NULL)
            return sm12_fault(a,SM08_GUARD,13u,address,value);
        status=a->static_owner.before_write(a->static_owner.context,a,address,value);
        if(status!=SM08_OK) return sm12_fault(a,status,13u,address,value);
    }
    /* The underlying ARAM write happens even for write-only/ignored MMIO. */
    a->aram[address] = value;
    if (address < 0xF0u || address > 0xFFu) return SM08_OK;
    if (address >= 0xF4u && address <= 0xF7u) {
        a->smp_output[address - 0xF4u] = value;
        a->output_half[address - 0xF4u] = a->completed_half + 2u;
        return SM08_OK;
    }
    if (address == 0xF8u || address == 0xF9u) {
        a->aux[address - 0xF8u] = value;
        return SM08_OK;
    }
    if (address >= 0xFDu) return SM08_OK;
    if (address==0xF0u && (a->ipl.psw & 0x20u)!=0u) return SM08_OK;
    if (address==0xF3u) {
        if(a->dsp_address>=0x80u) return SM08_OK;
        if(a->dsp.write==NULL) return sm12_fault(a,SM08_REGISTER,16u,address,value);
        status=a->dsp.write(a->dsp.context,a->dsp_address,value);
        return status==SM08_OK ? status : sm12_fault(a,status,16u,address,value);
    }
    status = sm12_known(a, address, value, &byte);
    if (status != SM08_OK) return status;
    if (address == 0xF0u) {
        /* P=1 ignores TEST. Other clock/RAM control modes are unsupported. */
        if ((a->ipl.psw & 0x20u) == 0u && byte != 0x0Au)
            return sm12_fault(a, SM08_REGISTER, 12u, address, value);
    } else if (address == 0xF1u) sm12_control(a, byte);
    else if (address == 0xF2u) a->dsp_address = byte;
    else if (address >= 0xFAu) a->timers[address - 0xFAu].target = byte;
    return SM08_OK;
}

static Sm08Status sm12_read_event(Sm12Apu *a, uint16_t address, uint8_t *out, uint8_t consumed) {
    Sm08Value v;
    Sm08Status status = sm12_apu_smp_read(a, address, &v);
    if (status != SM08_OK) return status;
    ++a->bus_events;
    if (consumed != 0u) return sm12_known(a, address, v, out);
    *out = v.value; /* Dummy bus reads retain effects but do not consume tags. */
    return SM08_OK;
}

static Sm08Status sm12_write_event(Sm12Apu *a, uint16_t address, uint8_t value) {
    Sm08Status status = sm12_apu_smp_write(a, address, (Sm08Value){value,0xFFu});
    if (status == SM08_OK) ++a->bus_events;
    return status;
}

static void sm12_timer_tick(Sm12Timer *t, uint16_t period) {
    t->prescaler = (uint16_t)(t->prescaler + 1u);
    if (t->prescaler == period) {
        t->prescaler = 0u;
        if (t->enabled != 0u) {
            t->stage = (uint8_t)(t->stage + 1u);
            if (t->stage == t->target) {
                t->stage = 0u;
                t->output = (uint8_t)((t->output + 1u) & 15u);
            }
        }
    }
}

/* Only static architectural PCs are accepted. This is not opcode decoding. */
static Sm08Status sm12_begin(Sm12Apu *a) {
    Sm12Ipl *s = &a->ipl;
    uint8_t cycles = 0u, length = 0u, taken = 0u;
    switch (s->pc) {
        case 0xFFC0: case 0xFFC3: length=2u; cycles=2u; break;
        case 0xFFC2: case 0xFFC6: case 0xFFE4: case 0xFFF7: case 0xFFF8:
            length=1u; cycles=2u; break;
        case 0xFFC5: length=1u; cycles=4u; break;
        case 0xFFC9: case 0xFFCC: case 0xFFCF: length=3u; cycles=5u; break;
        case 0xFFD4: length=2u; cycles=4u; break;
        case 0xFFD6: case 0xFFDA: case 0xFFDE: case 0xFFEB: length=2u; cycles=3u; break;
        case 0xFFE0: case 0xFFE7: case 0xFFF5: length=2u; cycles=4u; break;
        case 0xFFE2: length=2u; cycles=7u; break;
        case 0xFFEF: case 0xFFF1: case 0xFFF3: length=2u; cycles=5u; break;
        case 0xFFFB: length=3u; cycles=6u; break;
        case 0xFFC7: case 0xFFD2: case 0xFFD8: case 0xFFDC: case 0xFFE5: case 0xFFF9:
            length=2u; taken=(uint8_t)((s->psw & 2u)==0u); cycles=(uint8_t)(2u+2u*taken); break;
        case 0xFFE9: case 0xFFED:
            length=2u; taken=(uint8_t)((s->psw & 0x80u)==0u); cycles=(uint8_t)(2u+2u*taken); break;
        default: return sm12_fault(a,SM08_GUARD,12u,s->pc,(Sm08Value){0u,0u});
    }
    s->active_pc=s->pc; s->length=length; s->remaining=cycles;
    s->cycle=0u; s->branch_taken=taken; s->active=1u;
    return SM08_OK;
}

static Sm08Status sm12_header_source(Sm12Apu *a) {
    uint16_t pointer;
    if (a->source.record_count == 0u) return SM08_OK;
    if (a->record_open != 0u) {
        if (a->record_written != a->source.records[a->record_index].length)
            return sm12_fault(a,SM08_GUARD,12u,0xFFF3u,(Sm08Value){a->ipl.y,0xFFu});
        ++a->record_index;
        a->record_open=0u;
    }
    if (a->aram[0].known_mask != 0xFFu || a->aram[1].known_mask != 0xFFu)
        return sm12_fault(a,SM08_UNKNOWN,12u,0u,a->aram[0]);
    pointer=(uint16_t)(a->aram[0].value | ((uint16_t)a->aram[1].value<<8));
    if (a->ipl.y != 0u) {
        if (a->record_index >= a->source.record_count ||
            pointer != a->source.records[a->record_index].destination)
            return sm12_fault(a,SM08_GUARD,12u,pointer,(Sm08Value){a->ipl.y,0xFFu});
        a->record_open=1u; a->record_written=0u;
    } else if (a->record_index != a->source.record_count || pointer != a->source.entry)
        return sm12_fault(a,SM08_GUARD,12u,pointer,(Sm08Value){a->ipl.y,0xFFu});
    return SM08_OK;
}

static Sm08Status sm12_payload(Sm12Apu *a, uint16_t address) {
    Sm08Status status;
    if (a->source.record_count != 0u) {
        const Sm12UploadRecord *r;
        if (a->record_open == 0u || a->record_index >= a->source.record_count)
            return sm12_fault(a,SM08_GUARD,12u,address,(Sm08Value){a->ipl.a,0xFFu});
        r=&a->source.records[a->record_index];
        if (a->record_written >= r->length || address != (uint16_t)(r->destination+a->record_written) ||
            a->ipl.a != a->bus->memory.rom[r->rom_offset+a->record_written])
            return sm12_fault(a,SM08_GUARD,12u,address,(Sm08Value){a->ipl.a,0xFFu});
    }
    status=sm12_write_event(a,address,a->ipl.a);
    if (status != SM08_OK) return status;
    if (a->source.record_count != 0u) {
        if (a->record_written == 0u) ++a->upload_epoch;
        ++a->record_written; ++a->uploaded_bytes;
    }
    return SM08_OK;
}

static Sm08Status sm12_ack(Sm12Apu *a, uint8_t header) {
    if (header == 0u && a->source.fresh_data_per_byte != 0u &&
        (a->token_sequence <= a->consumed_token_sequence || a->data_sequence <= a->consumed_data_sequence))
        return sm12_fault(a,SM08_GUARD,12u,0xF4u,(Sm08Value){a->ipl.y,0xFFu});
    a->ack_token_sequence=header!=0u ? a->ipl.low_sequence : a->token_sequence;
    a->ack_data_sequence=header!=0u ? a->ipl.high_sequence : a->data_sequence;
    a->ack_half=a->completed_half+2u;
    /* Header flag/data has already been consumed too. The first payload byte
     * needs its own data write, not a fresh-looking old header flag. */
    a->consumed_token_sequence=a->ack_token_sequence;
    a->consumed_data_sequence=a->ack_data_sequence;
    return sm12_write_event(a,0xF4u,header!=0u ? a->ipl.a : a->ipl.y);
}

static Sm08Status sm12_event(Sm12Apu *a) {
    Sm12Ipl *s=&a->ipl;
    uint8_t v=0u, c=s->cycle;
    uint16_t address;
    Sm08Status status;
    if (c <= s->length) {
        address=(uint16_t)(s->active_pc+c-1u);
        status=sm12_read_event(a,address,&v,1u);
        if (status != SM08_OK) return status;
        if (v != sm12_rom[address-0xFFC0u])
            return sm12_fault(a,SM08_GUARD,12u,address,(Sm08Value){v,0xFFu});
    }
    switch (s->active_pc) {
        case 0xFFC5:
            if (c==3u) return sm12_read_event(a,sm12_dp(a,s->x),&v,0u);
            if (c==4u) return sm12_write_event(a,sm12_dp(a,s->x),s->a);
            break;
        case 0xFFC9: case 0xFFCC:
            address=(uint16_t)(s->active_pc==0xFFC9u ? 0xF4u : 0xF5u);
            if (c==4u) return sm12_read_event(a,address,&v,0u);
            if (c==5u) return sm12_write_event(a,address,(uint8_t)(s->active_pc==0xFFC9u ? 0xAAu : 0xBBu));
            break;
        case 0xFFCF:
            if (c==4u) {
                status=sm12_read_event(a,0xF4u,&v,1u);
                if (status!=SM08_OK) return status;
                sm12_compare(a,v,0xCCu);
            }
            break;
        case 0xFFD6: case 0xFFDA: case 0xFFEB:
            if (c==3u) {
                status=sm12_read_event(a,0xF4u,&v,1u);
                if (status!=SM08_OK) return status;
                if (s->active_pc==0xFFD6u) { s->y=v; sm12_nz(a,v); }
                else { sm12_compare(a,s->y,v); a->token_sequence=a->sampled_sequence[0]; }
            }
            break;
        case 0xFFDE:
            if (c==3u) {
                status=sm12_read_event(a,0xF5u,&s->a,1u);
                if (status!=SM08_OK) return status;
                sm12_nz(a,s->a); a->data_sequence=a->sampled_sequence[1];
            }
            break;
        case 0xFFE0: case 0xFFF5:
            if (c==3u) return sm12_read_event(a,0xF4u,&v,0u);
            if (c==4u) return sm12_ack(a,(uint8_t)(s->active_pc==0xFFF5u));
            break;
        case 0xFFE2:
            if (c==3u) return sm12_read_event(a,sm12_dp(a,0u),&s->low,1u);
            if (c==4u) return sm12_read_event(a,sm12_dp(a,1u),&s->high,1u);
            if (c==7u) return sm12_payload(a,(uint16_t)(s->low+((uint16_t)s->high<<8)+s->y));
            break;
        case 0xFFE7:
            if (c==3u) {
                status=sm12_read_event(a,sm12_dp(a,1u),&s->data,1u);
                if (status!=SM08_OK) return status;
                s->data=(uint8_t)(s->data+1u); sm12_nz(a,s->data);
            }
            if (c==4u) return sm12_write_event(a,sm12_dp(a,1u),s->data);
            break;
        case 0xFFEF: case 0xFFF3:
            address=(uint16_t)(s->active_pc==0xFFEFu ? 0xF6u : 0xF4u);
            if (c==3u) {
                status=sm12_read_event(a,address,&s->low,1u);
                if (status!=SM08_OK) return status;
                s->low_sequence=a->sampled_sequence[address-0xF4u];
            }
            if (c==5u) {
                status=sm12_read_event(a,(uint16_t)(address+1u),&s->high,1u);
                if (status!=SM08_OK) return status;
                s->high_sequence=a->sampled_sequence[address+1u-0xF4u];
                s->a=s->low; s->y=s->high;
                sm12_nz16(a,(uint16_t)(s->a+((uint16_t)s->y<<8)));
                if (s->active_pc==0xFFF3u) return sm12_header_source(a);
            }
            break;
        case 0xFFF1:
            if (c==4u) return sm12_write_event(a,sm12_dp(a,0u),s->a);
            if (c==5u) return sm12_write_event(a,sm12_dp(a,1u),s->y);
            break;
        case 0xFFFB:
            if (c==5u) return sm12_read_event(a,s->x,&s->low,1u);
            if (c==6u) return sm12_read_event(a,(uint16_t)(s->x+1u),&s->high,1u);
            break;
        default: break;
    }
    return SM08_OK;
}

static void sm12_complete(Sm12Apu *a) {
    Sm12Ipl *s=&a->ipl;
    uint16_t next=(uint16_t)(s->active_pc+s->length);
    switch (s->active_pc) {
        case 0xFFC0: s->x=0xEFu; sm12_nz(a,s->x); break;
        case 0xFFC2: s->sp=s->x; break;
        case 0xFFC3: s->a=0u; sm12_nz(a,0u); break;
        case 0xFFC6: s->x=(uint8_t)(s->x-1u); sm12_nz(a,s->x); break;
        case 0xFFC7: if(s->branch_taken!=0u) next=0xFFC5u; break;
        case 0xFFD2: if(s->branch_taken!=0u) next=0xFFCFu; break;
        case 0xFFD4: next=0xFFEFu; break;
        case 0xFFD8: if(s->branch_taken!=0u) next=0xFFD6u; break;
        case 0xFFDC: if(s->branch_taken!=0u) next=0xFFE9u; break;
        case 0xFFE4: s->y=(uint8_t)(s->y+1u); sm12_nz(a,s->y); break;
        case 0xFFE5: case 0xFFE9: case 0xFFED: if(s->branch_taken!=0u) next=0xFFDAu; break;
        case 0xFFF7: s->a=s->y; sm12_nz(a,s->a); break;
        case 0xFFF8: s->x=s->a; sm12_nz(a,s->x); break;
        case 0xFFF9: if(s->branch_taken!=0u) next=0xFFD6u; break;
        case 0xFFFB:
            next=(uint16_t)(s->low+((uint16_t)s->high<<8));
            a->jump_entry=next; a->jump_half=a->completed_half+2u;
            a->phase=SM12_ENTRY_PENDING;
            break;
        default: break;
    }
    s->pc=next; s->active=0u;
}

static void sm12_publish(Sm12Apu *a) {
    uint8_t i;
    for (i=0u;i<4u;++i) if ((a->pending_mask & (1u<<i))!=0u) {
        a->cpu_input[i]=a->pending_input[i];
        a->visible_sequence[i]=a->pending_sequence[i];
    }
    a->pending_mask=0u;
}

Sm08Status sm12_apu_sync_half(Sm12Apu *a, uint64_t target) {
    Sm08Status status;
    if (!sm12_attached(a)) return SM08_ARGUMENT;
    if (a->bus->fault.status != SM08_OK) return a->bus->fault.status;
    if (a->phase==SM12_FAILED) return SM08_GUARD;
    if (target<a->completed_half) return sm12_fault(a,SM08_GUARD,12u,a->ipl.pc,(Sm08Value){0u,0u});
    if (a->phase==SM12_ENTRY_REQUIRED && target>a->completed_half)
        return sm08_bus_fault(a->bus,SM08_GUARD,13u,a->entry_pc,a->entry_byte);
    while (target-a->completed_half>=2u) {
        if (a->completed_half>UINT64_MAX-2u || a->smp_cycles==UINT64_MAX)
            return sm12_fault(a,SM08_GUARD,12u,a->ipl.pc,(Sm08Value){0u,0u});
        if (a->phase==SM12_IPL && a->startup_remaining==0u && a->ipl.active==0u) {
            status=sm12_begin(a); if(status!=SM08_OK) return status;
        }
        sm12_timer_tick(&a->timers[0],128u);
        sm12_timer_tick(&a->timers[1],128u);
        sm12_timer_tick(&a->timers[2],16u);
        if (a->dsp.step!=NULL) {
            status=a->dsp.step(a->dsp.context,a->bus,a->smp_cycles+1u,a->dsp_phase);
            if(status!=SM08_OK) return sm12_fault(a,status,16u,0xF3u,(Sm08Value){0u,0u});
        }
        a->dsp_phase=(uint8_t)((a->dsp_phase+1u)&31u);
        if (a->startup_remaining!=0u) --a->startup_remaining;
        else if (a->phase==SM12_ENTRY_PENDING) {
            Sm08Value byte;
            if (a->source.record_count!=0u &&
                (a->ipl.pc!=a->source.entry || a->record_index!=a->source.record_count || a->record_open!=0u))
                return sm12_fault(a,SM08_GUARD,12u,a->ipl.pc,(Sm08Value){0u,0u});
            status=sm12_apu_smp_read(a,a->ipl.pc,&byte);
            if(status!=SM08_OK) return status;
            if(byte.known_mask!=0xFFu) return sm12_fault(a,SM08_UNKNOWN,13u,a->ipl.pc,byte);
            ++a->bus_events;
            a->entry_pc=a->ipl.pc; a->entry_byte=byte;
            a->entry_half=a->completed_half+2u; a->entry_prefetched=1u;
            a->phase=SM12_ENTRY_REQUIRED;
            if(a->static_owner.enter!=NULL) {
                status=a->static_owner.enter(a->static_owner.context,a);
                if(status!=SM08_OK) return sm12_fault(a,status,13u,a->entry_pc,a->entry_byte);
                a->phase=SM12_STATIC_RUNNING;
            }
        } else if(a->phase==SM12_STATIC_RUNNING) {
            if(a->static_owner.cycle==NULL)
                return sm12_fault(a,SM08_GUARD,13u,a->entry_pc,a->entry_byte);
            status=a->static_owner.cycle(a->static_owner.context,a);
            if(status!=SM08_OK) return sm12_fault(a,status,13u,a->entry_pc,a->entry_byte);
        } else {
            ++a->ipl.cycle;
            status=sm12_event(a); if(status!=SM08_OK) return status;
            --a->ipl.remaining;
            if(a->ipl.remaining==0u) sm12_complete(a);
        }
        sm12_publish(a);
        a->completed_half+=2u; ++a->smp_cycles;
        if(a->phase==SM12_ENTRY_REQUIRED)
            return sm08_bus_fault(a->bus,SM08_GUARD,13u,a->entry_pc,a->entry_byte);
    }
    return SM08_OK;
}

Sm08Status sm12_apu_sync_current(Sm12Apu *a) {
    uint64_t whole,target;
    if(!sm12_attached(a)) return SM08_ARGUMENT;
    whole=a->scheduler->smp.target_cycles;
    if(whole>UINT64_MAX/2u) return sm12_fault(a,SM08_GUARD,12u,a->ipl.pc,(Sm08Value){0u,0u});
    target=whole*2u+(uint64_t)((2u*a->scheduler->smp.remainder)/SM09_SMP_DENOMINATOR);
    return sm12_apu_sync_half(a,target);
}

static Sm08Status sm12_cpu_read(void *context, uint16_t address, Sm08Drive *drive) {
    Sm12Apu *a=context;
    Sm08Status status;
    uint8_t p;
    if(!sm12_attached(a) || drive==NULL || address<0x2140u || address>0x217Fu) return SM08_ARGUMENT;
    status=sm12_apu_sync_current(a); if(status!=SM08_OK) return status;
    p=(uint8_t)((address-0x2140u)&3u);
    drive->value=a->smp_output[p].value; drive->known_mask=a->smp_output[p].known_mask;
    drive->driven_mask=0xFFu; ++a->reads[p];
    return SM08_OK;
}

static Sm08Status sm12_cpu_write(void *context, uint16_t address, Sm08Value value) {
    Sm12Apu *a=context;
    Sm08Status status;
    uint64_t target;
    uint8_t p;
    if(!sm12_attached(a) || address<0x2140u || address>0x217Fu) return SM08_ARGUMENT;
    status=sm12_apu_sync_current(a); if(status!=SM08_OK) return status;
    if(a->write_sequence==UINT64_MAX) return sm12_fault(a,SM08_GUARD,12u,address,value);
    p=(uint8_t)((address-0x2140u)&3u);
    ++a->write_sequence; ++a->writes[p];
    a->pending_input[p]=value; a->pending_sequence[p]=a->write_sequence;
    a->pending_mask|=(uint8_t)(1u<<p);
    target=a->scheduler->smp.target_cycles*2u+
        (uint64_t)((2u*a->scheduler->smp.remainder)/SM09_SMP_DENOMINATOR);
    if(target<=a->completed_half) sm12_publish(a);
    return SM08_OK;
}

Sm08Device sm12_apu_device(Sm12Apu *a) {
    Sm08Device device={a,sm12_cpu_read,sm12_cpu_write};
    return device;
}

static Sm08Status sm12_smp_sync(void *context, Sm08Bus *bus, uint64_t target) {
    Sm12Apu *a=context;
    if(!sm12_attached(a) || bus!=a->bus || target!=a->scheduler->smp.target_cycles) return SM08_ARGUMENT;
    return sm12_apu_sync_current(a);
}

static Sm08Status sm12_raster(void *context, Sm08Bus *bus, const Sm09Scheduler *s, Sm09RasterEvent event) {
    Sm12Apu *a=context;
    if(!sm12_attached(a) || bus!=a->bus || s!=a->scheduler) return SM08_ARGUMENT;
    return a->downstream.raster_event(a->downstream.context,bus,s,event);
}

static Sm08Status sm12_boundary(void *context, Sm08Bus *bus, const Sm09Scheduler *s,
                               uint8_t kind,uint32_t address,uint8_t clocks) {
    Sm12Apu *a=context;
    if(!sm12_attached(a) || bus!=a->bus || s!=a->scheduler) return SM08_ARGUMENT;
    return a->downstream.cpu_boundary(a->downstream.context,bus,s,kind,address,clocks);
}

Sm08Status sm12_apu_bind(Sm12Apu *a) {
    if(!sm12_attached(a) || a->bound!=0u || a->scheduler->advancing!=0u ||
       a->scheduler->master_clock!=0u || a->bus->ports.apuio.read!=NULL ||
       a->bus->ports.apuio.write!=NULL || a->scheduler->receivers.raster_event==NULL ||
       a->scheduler->receivers.cpu_boundary==NULL || a->scheduler->receivers.context==a) return SM08_ARGUMENT;
    if(a->bus->fault.status!=SM08_OK) return a->bus->fault.status;
    a->downstream=a->scheduler->receivers;
    a->bus->ports.apuio=sm12_apu_device(a);
    a->scheduler->receivers=(Sm09Receivers){a,sm12_smp_sync,sm12_raster,sm12_boundary};
    a->bound=1u;
    return SM08_OK;
}

Sm08Status sm12_apu_configure_source(Sm12Apu *a, Sm12UploadContract source) {
    uint32_t i;
    if(!sm12_attached(a) || a->smp_cycles!=0u || a->bound!=0u ||
       (source.record_count!=0u && source.records==NULL) || source.fresh_data_per_byte>1u) return SM08_ARGUMENT;
    for(i=0u;i<source.record_count;++i) {
        const Sm12UploadRecord *r=&source.records[i];
        if(r->length==0u || r->length>65536u || (uint32_t)r->destination+r->length>65536u ||
           r->rom_offset>a->bus->memory.rom_size || r->length>a->bus->memory.rom_size-r->rom_offset)
            return SM08_ARGUMENT;
    }
    a->source=source;
    return SM08_OK;
}

Sm08Status sm12_apu_bind_dsp(Sm12Apu *a, Sm12DspPort dsp) {
    if(!sm12_attached(a) || a->smp_cycles!=0u || a->bound!=0u ||
       ((dsp.read==NULL)!=(dsp.write==NULL))) return SM08_ARGUMENT;
    a->dsp=dsp;
    return SM08_OK;
}

Sm08Status sm12_apu_bind_static(Sm12Apu *a, Sm12StaticPort owner) {
    Sm08Status status;
    if(!sm12_attached(a) || owner.context==NULL || owner.enter==NULL ||
       owner.cycle==NULL || owner.before_write==NULL ||
       a->static_owner.enter!=NULL || a->scheduler->advancing!=0u) return SM08_ARGUMENT;
    if(a->smp_cycles==0u && a->bound==0u && a->phase==SM12_IPL) {
        if(a->bus->fault.status!=SM08_OK) return a->bus->fault.status;
        a->static_owner=owner;
        return SM08_OK;
    }
    /* Only the exact12 typed stop is adopted, never arbitrary host PC entry. */
    if(a->phase!=SM12_ENTRY_REQUIRED || a->entry_prefetched==0u ||
       a->entry_byte.known_mask!=0xFFu || a->entry_pc!=a->ipl.pc ||
       a->entry_half!=a->completed_half || a->jump_half>=a->entry_half ||
       a->bus->fault.status!=SM08_GUARD || a->bus->fault.owner!=13u ||
       a->bus->fault.address!=a->entry_pc ||
       a->bus->fault.sample.value!=a->entry_byte.value ||
       a->bus->fault.sample.known_mask!=a->entry_byte.known_mask) return SM08_ARGUMENT;
    status=owner.enter(owner.context,a);
    if(status!=SM08_OK) return status;
    a->static_owner=owner;
    a->bus->fault=(Sm08Fault){SM08_OK,0u,0u,{0u,0u}};
    a->phase=SM12_STATIC_RUNNING;
    return SM08_OK;
}

Sm08Status sm12_apu_power_on(Sm12Apu *a, Sm08Bus *bus, Sm09Scheduler *scheduler) {
    uint8_t i;
    if(a==NULL || bus==NULL || scheduler==NULL || scheduler->bus!=bus || scheduler->master_clock!=0u ||
       scheduler->smp.target_cycles!=0u || scheduler->smp.remainder!=0u) return SM08_ARGUMENT;
    if(bus->fault.status!=SM08_OK) return bus->fault.status;
    memset(a,0,sizeof(*a));
    a->bus=bus; a->scheduler=scheduler;
    a->ipl.pc=0xFFC0u; a->ipl.psw=2u; a->phase=SM12_IPL;
    a->startup_remaining=SM12_STARTUP_CYCLES;
    for(i=0u;i<3u;++i) a->timers[i].output=15u;
    sm12_control(a,0xB0u);
    return SM08_OK;
}

Sm08Status sm12_apu_cpu_reset(Sm12Apu *a) {
    return sm12_attached(a) ? SM08_OK : SM08_ARGUMENT;
}

Sm08Status sm12_apu_smp_reset(Sm12Apu *a) {
    uint8_t i;
    if(!sm12_attached(a)) return SM08_ARGUMENT;
    /* Independent SMP reset retains ARAM, targets, stage1 and oscillator time. */
    for(i=0u;i<3u;++i) { a->timers[i].enabled=0u; a->timers[i].stage=0u; a->timers[i].output=0u; }
    a->ipl=(Sm12Ipl){0}; a->ipl.pc=0xFFC0u; a->ipl.psw=2u;
    a->phase=SM12_IPL; a->startup_remaining=SM12_STARTUP_CYCLES;
    a->record_index=0u; a->record_written=0u; a->record_open=0u; a->entry_prefetched=0u;
    a->consumed_token_sequence=0u; a->consumed_data_sequence=0u;
    sm12_control(a,0xB0u);
    return SM08_OK;
}

Sm08Status sm12_apu_restart_ipl(Sm12Apu *a) {
    if(!sm12_attached(a) || a->ipl.active!=0u || a->bus->fault.status!=SM08_OK) return SM08_ARGUMENT;
    a->ipl.pc=0xFFC0u; a->phase=SM12_IPL; a->startup_remaining=0u;
    a->record_index=0u; a->record_written=0u; a->record_open=0u; a->entry_prefetched=0u;
    return SM08_OK;
}
