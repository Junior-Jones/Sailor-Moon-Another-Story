#include "sailor_moon_core_state.h"
#include "../generated/integration/sailor_moon_core_build_identity.h"
#include <stdlib.h>
#include <string.h>

/* Actual own12 source records, validation only. No ARAM is seeded here. */
static const Sm12UploadRecord sm17_upload_records[]={{0x1e07c5u,4839u,0x0380u}};

static SmCoreStatus sm17_status(Sm08Status status) { return (SmCoreStatus)status; }

int sm17_options_valid(const SmCoreOptions *o) {
    if(o==NULL || o->version!=SM_CORE_OPTIONS_VERSION ||
       o->cold_storage_profile>SM_CORE_DETERMINISTIC_ZERO_STORAGE_APUIO_V1 ||
       memchr(o->name,0,sizeof(o->name))==NULL || o->name[0]==0 ||
       o->cpu_e>1u || o->pads[0].present>1u || o->pads[1].present>1u) return 0;
    if(o->cpu_e && ((o->cpu_p & (SM_P_M|SM_P_X))!=(SM_P_M|SM_P_X) ||
                      (o->cpu_s & 0xff00u)!=0x0100u)) return 0;
    if((o->cpu_p & SM_P_X) && ((o->cpu_x|o->cpu_y)&0xff00u)) return 0;
    return 1;
}

static void sm17_options_copy(SmCoreOptions *d,const SmCoreOptions *s) {
    unsigned i;
    memset(d,0,sizeof(*d));
    d->version=s->version;
    d->cold_storage_profile=s->cold_storage_profile;
    for(i=0u;i<sizeof(d->name)-1u && s->name[i]!=0;++i) d->name[i]=s->name[i];
    d->cpu_a=s->cpu_a; d->cpu_x=s->cpu_x; d->cpu_y=s->cpu_y;
    d->cpu_s=s->cpu_s; d->cpu_d=s->cpu_d;
    d->cpu_pbr=s->cpu_pbr; d->cpu_dbr=s->cpu_dbr; d->cpu_p=s->cpu_p; d->cpu_e=s->cpu_e;
    d->external_pin_value=s->external_pin_value;
    d->external_pin_known_mask=s->external_pin_known_mask;
    for(i=0u;i<2u;++i) {
        d->pads[i].value=s->pads[i].value;
        d->pads[i].known_mask=s->pads[i].known_mask;
        d->pads[i].present=s->pads[i].present;
    }
}

void sm_core_options_functional_neutral_v1(SmCoreOptions *o) {
    if(o==NULL) return;
    memset(o,0,sizeof(*o));
    o->version=SM_CORE_OPTIONS_VERSION;
    memcpy(o->name,"FUNCTIONAL_NEUTRAL_V1",22u);
    o->cpu_e=1u; o->cpu_p=0x34u; o->cpu_s=0x0100u;
    o->pads[0].present=1u;
    o->pads[0].known_mask=0xffffu; o->pads[1].known_mask=0xffffu;
    /* External pins unknown, all unforced registers explicit representatives.
     * WRAM/video/ARAM retain their owners' unknown cold policies. */
}

void sm_core_options_deterministic_zero_storage_v1(SmCoreOptions *o) {
    if(o==NULL) return;
    sm_core_options_functional_neutral_v1(o);
    memset(o->name,0,sizeof(o->name));
    memcpy(o->name,"DETERMINISTIC_ZERO_STORAGE_V1",30u);
    o->cold_storage_profile=SM_CORE_DETERMINISTIC_ZERO_STORAGE_V1;
}

void sm_core_options_deterministic_zero_storage_apuio_v1(SmCoreOptions *o) {
    if(o==NULL) return;
    sm_core_options_deterministic_zero_storage_v1(o);
    memset(o->name,0,sizeof(o->name));
    memcpy(o->name,"ZERO_STORAGE_APUIO_V1",21u);
    o->cold_storage_profile=SM_CORE_DETERMINISTIC_ZERO_STORAGE_APUIO_V1;
}

/* Selected cold image, not architectural register initialization or a read
 * exception. Whole domains avoid per-address fixes learned from a failure. */
static void sm17_zero_wram(Sm08Memory *memory) {
    memset(memory->wram,0,sizeof(memory->wram));
    memset(memory->wram_known,0xff,sizeof(memory->wram_known));
}
static void sm17_zero_ppu_storage(Sm11Ppu *ppu) {
    unsigned i;
    const Sm08Value zero={0u,255u};
    for(i=0u;i<SM11_VRAM_BYTES;++i) ppu->vram[i]=zero;
    for(i=0u;i<SM11_CGRAM_BYTES;++i) ppu->cgram[i]=zero;
    for(i=0u;i<SM11_OAM_BYTES;++i) ppu->oam[i]=zero;
}
static void sm17_zero_aram_storage(Sm12Apu *apu) {
    unsigned i;
    const Sm08Value zero={0u,255u};
    for(i=0u;i<SM12_ARAM_BYTES;++i) apu->aram[i]=zero;
    /* Physical backing only: IPL overlay and F0..FF MMIO retain their real
     * read/write owners, defaults, latches, effects and knownness rules. */
}

static void sm17_zero_apuio_cold_latches(Sm12Apu *apu) {
    unsigned i;
    const Sm08Value zero={0u,255u};
    for(i=0u;i<4u;++i) {
        apu->cpu_input[i]=zero;
        apu->smp_output[i]=zero;
    }
    /* This is an initial latch image, not an SMP/CPU store: pending_mask,
     * write/visible/sampled sequences, timestamps, counters and ARAM backing
     * are untouched. Pending values acquire authority only on actual writes. */
}

int sm17_assembled(const SmCore *c) {
    const Sm17State *s;
    if(c==NULL || c->rom==NULL) return 0;
    s=&c->state;
    return s->storage.bus.memory.rom==c->rom &&
      s->storage.bus.memory.rom_size==SM_CORE_ROM_BYTES &&
      s->storage.io.bus==&s->storage.bus && s->scheduler.bus==&s->storage.bus &&
      s->clock.bus==&s->storage.bus && s->clock.math==&s->storage.io.math &&
      s->machine.storage==&s->storage && s->machine.scheduler==&s->scheduler &&
      s->machine.clock==&s->clock && s->machine.cpu==&s->cpu &&
      s->ppu.bus==&s->storage.bus && s->renderer.ppu==&s->ppu &&
      s->apu.bus==&s->storage.bus && s->spc.apu==&s->apu &&
      s->dsp.apu==&s->apu && s->dsp.bus==&s->storage.bus &&
      s->input.bus==&s->storage.bus && s->dma.bus==&s->storage.bus &&
      s->scheduler.receivers.context==&s->dma &&
      s->ppu.bound && s->renderer.bound && s->apu.bound && s->dsp.bound && s->input.bound;
}

static Sm08Status sm17_pin_sample(void *context,Sm08Value *out) {
    SmCore *c=context;
    if(c==NULL || out==NULL) return SM08_ARGUMENT;
    *out=(Sm08Value){c->options.external_pin_value,c->options.external_pin_known_mask};
    return SM08_OK;
}
static Sm08Status sm17_pin_drive(void *context,Sm08Value prior,Sm08Value next) {
    SmCore *c=context;
    if(c==NULL) return SM08_ARGUMENT;
    if((prior.known_mask & next.known_mask & 0x80u)!=0u &&
       (prior.value & 0x80u)!=0u && (next.value & 0x80u)==0u) {
        if(!c->state.ppu.bound) return SM08_PPU_ABSENT;
        return sm11_ppu_latch_counters(&c->state.ppu);
    }
    return SM08_OK;
}
static Sm08Status sm17_terminal_smp(void *context,Sm08Bus *bus,uint64_t target) {
    (void)context; (void)bus; (void)target;
    return SM08_APUIO_ABSENT; /* Replaced by the actual12 receiver before release. */
}
static Sm08Status sm17_terminal_raster(void *context,Sm08Bus *bus,
                                      const Sm09Scheduler *scheduler,Sm09RasterEvent event) {
    SmCore *c=context;
    (void)event;
    if(c==NULL || bus!=&c->state.storage.bus || scheduler!=&c->state.scheduler)
        return SM08_ARGUMENT;
    if(c->state.raster_deliveries==UINT64_MAX) return SM08_CLOCK_ABSENT;
    ++c->state.raster_deliveries;
    return bus->fault.status;
}
static Sm08Status sm17_terminal_boundary(void *context,Sm08Bus *bus,
    const Sm09Scheduler *scheduler,uint8_t kind,uint32_t address,uint8_t clocks) {
    (void)context; (void)bus; (void)scheduler; (void)kind; (void)address; (void)clocks;
    return SM08_DMA_ABSENT; /* DMA last replaces, deliberately never delegates. */
}
static Sm08Status sm17_device_reset(void *context,Sm08Bus *bus,
    const Sm09Scheduler *scheduler,Sm09DeviceResetPhase phase,uint32_t hold) {
    SmCore *c=context;
    Sm17State *s;
    Sm08Status status;
    (void)hold;
    if(!sm17_assembled(c)) return SM08_ARGUMENT;
    s=&c->state;
    if(bus!=&s->storage.bus || scheduler!=&s->scheduler || s->dma.servicing)
        return SM08_ARGUMENT;
    if(phase==SM09_DEVICE_RESET_PREFLIGHT || phase==SM09_DEVICE_RESET_RELEASE) return SM08_OK;
    if(phase!=SM09_DEVICE_RESET_ASSERT) return SM08_ARGUMENT;
    status=sm11_ppu_reset(&s->ppu);
    if(status==SM08_OK) status=sm10_dma_reset(&s->dma);
    if(status==SM08_OK) status=sm15_input_cpu_reset(&s->input);
    if(status==SM08_OK) status=sm12_apu_cpu_reset(&s->apu);
    /* Independent SMP/DSP state, PCM and oscillator phase are preserved. */
    return status;
}

static Sm08Status sm17_assemble(SmCore *c,const uint8_t *battery,size_t size) {
    Sm17State *s=&c->state;
    Sm08Ports ports={0};
    Sm08Pins pins={c,sm17_pin_sample,sm17_pin_drive};
    Sm09Receivers receivers={c,sm17_terminal_smp,sm17_terminal_raster,sm17_terminal_boundary};
    Sm09DeviceResetPort reset={c,sm17_device_reset};
    Sm12UploadContract upload={sm17_upload_records,1u,0x0380u,1u};
    Sm15Physical physical={0};
    Sm08Status status;
    unsigned i;
    s->cpu.a=c->options.cpu_a; s->cpu.x=c->options.cpu_x; s->cpu.y=c->options.cpu_y;
    s->cpu.s=c->options.cpu_s; s->cpu.d=c->options.cpu_d; s->cpu.p=c->options.cpu_p;
    s->cpu.pbr=c->options.cpu_pbr; s->cpu.dbr=c->options.cpu_dbr; s->cpu.e=c->options.cpu_e;
    status=sm09_machine_construct(&s->machine,&s->storage,&s->scheduler,&s->clock,
                                  &s->cpu,c->rom,SM_CORE_ROM_BYTES,ports,pins,receivers);
    if(status==SM08_OK && c->options.cold_storage_profile>=SM_CORE_DETERMINISTIC_ZERO_STORAGE_V1)
        sm17_zero_wram(&s->storage.bus.memory);
    if(status==SM08_OK && battery!=NULL) status=sm08_sram_decode(&s->storage.bus.memory,battery,size);
    if(status==SM08_OK) status=sm11_ppu_power_on(&s->ppu,&s->storage.bus,&s->scheduler,&s->storage.io.wrio);
    if(status==SM08_OK && c->options.cold_storage_profile>=SM_CORE_DETERMINISTIC_ZERO_STORAGE_V1)
        sm17_zero_ppu_storage(&s->ppu);
    if(status==SM08_OK) status=sm11_ppu_bind(&s->ppu);
    if(status==SM08_OK) status=sm14_renderer_power_on(&s->renderer,&s->ppu);
    if(status==SM08_OK) status=sm14_renderer_bind(&s->renderer);
    if(status==SM08_OK) status=sm12_apu_power_on(&s->apu,&s->storage.bus,&s->scheduler);
    if(status==SM08_OK && c->options.cold_storage_profile>=SM_CORE_DETERMINISTIC_ZERO_STORAGE_V1)
        sm17_zero_aram_storage(&s->apu);
    if(status==SM08_OK && c->options.cold_storage_profile==SM_CORE_DETERMINISTIC_ZERO_STORAGE_APUIO_V1)
        sm17_zero_apuio_cold_latches(&s->apu);
    if(status==SM08_OK) status=sm12_apu_configure_source(&s->apu,upload);
    if(status==SM08_OK) status=sm16_sdsp_power_on(&s->dsp,&s->apu);
    if(status==SM08_OK) status=sm16_sdsp_bind(&s->dsp);
    if(status==SM08_OK) status=sm13_bind(&s->spc,&s->apu);
    if(status==SM08_OK) status=sm12_apu_bind(&s->apu);
    for(i=0u;i<2u;++i) {
        physical.present[i]=c->options.pads[i].present;
        physical.report[i]=(Sm15Word){c->options.pads[i].value,c->options.pads[i].known_mask};
    }
    if(status==SM08_OK) status=sm15_input_power_on(&s->input,&s->storage.bus,&s->scheduler,&physical);
    if(status==SM08_OK) status=sm15_input_bind(&s->input);
    if(status==SM08_OK) status=sm10_dma_bind(&s->dma,&s->storage.bus,&s->scheduler);
    if(status==SM08_OK && !sm17_assembled(c)) status=SM08_ARGUMENT;
    if(status==SM08_OK) status=sm09_machine_reset_with_devices(&s->machine,reset,0u);
    return status;
}

SmCore *sm_core_create(const uint8_t *rom,size_t size,const uint8_t *battery,
    size_t battery_size,const SmCoreOptions *options,SmCoreStatus *out) {
    SmCore *c;
    Sm08Status status;
    if(out!=NULL) *out=SM_CORE_ARGUMENT;
    if(!sm17_options_valid(options) || (battery==NULL && battery_size!=0u) ||
       (battery!=NULL && battery_size!=SM_CORE_SRAM_BYTES)) return NULL;
    if(size!=SM_CORE_ROM_BYTES || !sm08_rom_matches(rom,size)) {
        if(out!=NULL) *out=SM_CORE_BAD_ROM;
        return NULL;
    }
    c=calloc(1u,sizeof(*c));
    if(c==NULL) { if(out!=NULL) *out=SM_CORE_ALLOCATION; return NULL; }
    c->rom=malloc(SM_CORE_ROM_BYTES);
    if(c->rom==NULL) { free(c); if(out!=NULL) *out=SM_CORE_ALLOCATION; return NULL; }
    memcpy(c->rom,rom,SM_CORE_ROM_BYTES);
    sm17_options_copy(&c->options,options);
    status=sm17_assemble(c,battery,battery_size);
    if(status!=SM08_OK) {
        if(out!=NULL) *out=sm17_status(status);
        sm_core_destroy(c); return NULL;
    }
    if(out!=NULL) *out=SM_CORE_OK;
    return c;
}
void sm_core_destroy(SmCore *c) {
    if(c!=NULL && !c->busy) { free(c->rom); free(c); }
}
SmCoreStatus sm_core_hardware_reset(SmCore *c) {
    Sm08Status status;
    Sm09DeviceResetPort port={c,sm17_device_reset};
    if(!sm17_assembled(c) || c->busy) return SM_CORE_ARGUMENT;
    c->busy=1u;
    status=sm09_machine_reset_with_devices(&c->state.machine,port,0u);
    c->busy=0u;
    return sm17_status(status);
}
SmCoreStatus sm_core_cold_restart(SmCore *c) {
    uint8_t *battery,*oldrom;
    uint64_t generation=0u;
    SmCore *fresh;
    Sm17State *bindings;
    SmCoreStatus status=SM_CORE_OK;
    Sm08Status input_status=SM08_OK;
    unsigned i;
    if(!sm17_assembled(c) || c->busy) return SM_CORE_ARGUMENT;
    battery=malloc(SM_CORE_SRAM_BYTES); bindings=malloc(sizeof(*bindings));
    if(battery==NULL || bindings==NULL) { free(battery); free(bindings); return SM_CORE_ALLOCATION; }
    if(sm08_sram_encode(&c->state.storage.bus.memory,battery,SM_CORE_SRAM_BYTES,&generation)!=SM08_OK) {
        free(battery); free(bindings); return SM_CORE_BAD_SAVE;
    }
    fresh=sm_core_create(c->rom,SM_CORE_ROM_BYTES,battery,SM_CORE_SRAM_BYTES,&c->options,&status);
    free(battery);
    if(fresh==NULL) { free(bindings); return status; }
    for(i=0u;i<2u && input_status==SM08_OK;++i) {
        input_status=sm15_input_set_report(&fresh->state.input,i,c->state.input.physical.report[i]);
        if(input_status==SM08_OK)
            input_status=sm15_input_set_present(&fresh->state.input,i,c->state.input.physical.present[i]);
    }
    if(input_status==SM08_OK) input_status=sm15_input_cpu_reset(&fresh->state.input);
    if(input_status!=SM08_OK) {
        sm_core_destroy(fresh); free(bindings); return sm17_status(input_status);
    }
    *bindings=c->state;
    oldrom=c->rom; c->rom=fresh->rom;
    /* The configuration identity is immutable. Current physical reports are
     * retained runtime input, not a successor power/profile identity. */
    c->state=fresh->state;
    sm17_restore_bindings(&c->state,bindings);
    c->state.storage.bus.memory.rom=c->rom;
    fresh->rom=NULL;
    free(fresh); free(oldrom); free(bindings);
    return SM_CORE_OK;
}
SmCoreStatus sm_core_set_pad(SmCore *c,unsigned port,uint16_t value,uint16_t known) {
    if(!sm17_assembled(c) || c->busy) return SM_CORE_ARGUMENT;
    return sm17_status(sm15_input_set_report(&c->state.input,port,(Sm15Word){value,known}));
}
SmCoreStatus sm_core_set_present(SmCore *c,unsigned port,uint8_t present) {
    if(!sm17_assembled(c) || c->busy) return SM_CORE_ARGUMENT;
    return sm17_status(sm15_input_set_present(&c->state.input,port,present));
}

static SmCoreRunResult sm17_run(SmCore *c,uint64_t target,uint64_t limit,
    uint64_t *steps,SmCoreAudioProgress progress,void *context,int frame) {
    uint64_t count=0u,sequence;
    SmCoreRunResult result=SM_CORE_STOPPED;
    if(steps!=NULL) *steps=0u;
    if(!sm17_assembled(c) || c->busy || steps==NULL || limit==0u) return SM_CORE_BAD_ARGUMENT;
    sequence=c->state.renderer.sequence;
    c->busy=1u;
    for(;;) {
        if(c->state.storage.bus.fault.status!=SM08_OK || c->state.cpu.stopped ||
           c->state.cpu.failure_reason!=NULL) break;
        if(frame && c->state.renderer.sequence!=sequence) { result=SM_CORE_FRAME_READY; break; }
        if(c->state.scheduler.master_clock>=target) {
            result=frame ? SM_CORE_BUDGET : SM_CORE_TARGET_REACHED; break;
        }
        if(count==limit) { result=SM_CORE_BUDGET; break; }
        if(c->state.scpu_instructions==UINT64_MAX) {
            const Sm08Value unknown={0u,0u};
            sm08_bus_fault(&c->state.storage.bus,SM08_CLOCK_ABSENT,17u,sm_scpu_address(&c->state.cpu),unknown);
            break;
        }
        if(sm09_machine_step(&c->state.machine)!=SM_SCPU_EXECUTED) break;
        ++count; ++c->state.scpu_instructions;
        if(progress!=NULL && sm16_sdsp_pcm_available(&c->state.dsp)>=128u) progress(c,context);
    }
    c->busy=0u; *steps=count;
    return result;
}
SmCoreRunResult sm_core_run_to_frame(SmCore *c,uint64_t instructions,uint64_t clocks,
    uint64_t *steps,SmCoreAudioProgress progress,void *context) {
    if(c==NULL || clocks==0u || UINT64_MAX-c->state.scheduler.master_clock<clocks)
        return SM_CORE_BAD_ARGUMENT;
    return sm17_run(c,c->state.scheduler.master_clock+clocks,instructions,steps,progress,context,1);
}
SmCoreRunResult sm_core_run_until_master(SmCore *c,uint64_t target,uint64_t instructions,
    uint64_t *steps,SmCoreAudioProgress progress,void *context) {
    return sm17_run(c,target,instructions,steps,progress,context,0);
}
int sm_core_copy_frame(const SmCore *c,uint16_t *pixels,uint32_t capacity,uint8_t *known,
    uint32_t known_capacity,uint16_t *width,uint16_t *height,uint64_t *sequence) {
    return sm17_assembled(c) && sm14_renderer_copy_frame(&c->state.renderer,pixels,capacity,
                                                     known,known_capacity,width,height,sequence);
}
uint32_t sm_core_pcm_available(const SmCore *c) {
    return sm17_assembled(c) ? sm16_sdsp_pcm_available(&c->state.dsp) : 0u;
}
uint32_t sm_core_pcm_drain(SmCore *c,int16_t *data,uint8_t *known,uint32_t capacity) {
    return sm17_assembled(c) ? sm16_sdsp_pcm_drain(&c->state.dsp,data,known,capacity) : 0u;
}
int sm_core_pcm_metrics(const SmCore *c,Sm16PcmMetrics *out) {
    return sm17_assembled(c) && sm16_sdsp_pcm_metrics(&c->state.dsp,out);
}
int sm_core_timing(SmCoreTiming *out) {
    if(out==NULL) return 0;
    *out=(SmCoreTiming){236250000u,11u,39375000u,655171u,1024000u,32000u,
                        5632u,118125u,1364u,1360u,262u,256u,224u,186u};
    return 1;
}
int sm_core_build_identity(uint8_t out[32]) {
    if(out==NULL) return 0;
    memcpy(out,sm17_build_identity,32u); return 1;
}
SmCoreStatus sm_core_encode_sram(const SmCore *c,uint8_t *out,size_t size,uint64_t *generation) {
    if(!sm17_assembled(c) || c->busy) return SM_CORE_ARGUMENT;
    return sm17_status(sm08_sram_encode(&c->state.storage.bus.memory,out,size,generation));
}
int sm_core_ack_sram(SmCore *c,uint64_t generation) {
    return sm17_assembled(c) && !c->busy && sm08_memory_ack_sram(&c->state.storage.bus.memory,generation);
}
int sm_core_diagnostic(const SmCore *c,SmCoreDiagnostic *d) {
    const Sm17State *s;
    unsigned i;
    if(!sm17_assembled(c) || d==NULL) return 0;
    s=&c->state; memset(d,0,sizeof(*d));
    d->status=sm17_status(s->storage.bus.fault.status);
    d->cold_storage_profile=c->options.cold_storage_profile;
    d->options_version=c->options.version;
    d->failure_owner=s->storage.bus.fault.owner; d->failure_address=s->storage.bus.fault.address;
    d->failure_value=s->storage.bus.fault.sample.value; d->failure_known_mask=s->storage.bus.fault.sample.known_mask;
    if(s->cpu.failure_reason!=NULL) {
        for(i=0u;i<sizeof(d->failure_reason)-1u && s->cpu.failure_reason[i]!=0;++i)
            d->failure_reason[i]=s->cpu.failure_reason[i];
    }
    d->scpu_address=sm_scpu_address(&s->cpu); d->scpu_context=sm_scpu_context_key(&s->cpu);
    d->master_clock=s->scheduler.master_clock; d->completed_fields=s->scheduler.completed_fields;
    d->cpu_cycles=s->cpu.completed_cycles; d->scpu_instructions=s->scpu_instructions;
    d->smp_target=s->scheduler.smp.target_cycles; d->smp_remainder=s->scheduler.smp.remainder;
    d->smp_cycles=s->apu.smp_cycles; d->completed_half=s->apu.completed_half;
    d->apu_bus_events=s->apu.bus_events; d->upload_epoch=s->apu.upload_epoch;
    d->uploaded_bytes=s->apu.uploaded_bytes; d->published_sequence=s->renderer.sequence;
    d->raster_deliveries=s->raster_deliveries; d->dma_completed_bytes=s->dma.completed_bytes;
    d->scpu_a=s->cpu.a; d->scpu_x=s->cpu.x; d->scpu_y=s->cpu.y; d->scpu_s=s->cpu.s; d->scpu_d=s->cpu.d;
    d->scpu_p=s->cpu.p; d->scpu_e=s->cpu.e; d->scpu_pbr=s->cpu.pbr; d->scpu_dbr=s->cpu.dbr;
    d->scpu_stopped=s->cpu.stopped; d->scanline=s->scheduler.scanline; d->hclock=s->scheduler.hclock;
    d->dot=sm09_scheduler_dot(&s->scheduler); d->smp_pc=s->spc.pc; d->smp_active_pc=s->spc.active_pc;
    d->smp_return_depth=s->spc.return_depth; d->smp_active=s->spc.active;
    d->smp_cycle_index=s->spc.cycle_index; d->apu_phase=(uint8_t)s->apu.phase; d->dsp_phase=s->dsp.phase;
    d->dma_channel=s->dma.active_channel; d->hdma_enable=s->dma.hdma_enable; d->dma_servicing=s->dma.servicing;
    d->ppu_mode=s->ppu.registers[5].value & 7u; d->ppu_mode_known=s->ppu.registers[5].known_mask & 7u;
    d->ppu_blank=s->ppu.forced_blank; d->ppu_brightness=s->ppu.brightness.value;
    d->ppu_main=s->ppu.registers[0x2cu].value; d->ppu_main_known=s->ppu.registers[0x2cu].known_mask;
    for(i=0u;i<8u;++i) {
        if(s->dsp.voice[i].envelope.known) {
            d->active_voice_known_mask|=(uint8_t)(1u<<i);
            if(s->dsp.voice[i].envelope.value!=0) d->active_voice_mask|=(uint8_t)(1u<<i);
        }
    }
    d->render_status=(uint32_t)s->renderer.failure.status;
    d->render_dependency=(uint32_t)s->renderer.failure.dependency;
    d->render_address=s->renderer.failure.address; d->render_x=s->renderer.failure.x;
    d->render_y=s->renderer.failure.y; d->render_mask=s->renderer.failure.mask;
    d->render_known_mask=s->renderer.failure.known_mask;
    return sm16_sdsp_pcm_metrics(&s->dsp,&d->pcm);
}
