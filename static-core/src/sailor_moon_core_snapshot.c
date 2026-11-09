#include "sailor_moon_core_state.h"
#include <stdlib.h>
#include <string.h>

/* Native-ABI payload, explicitly bound to effective compiler/source identity.
 * No process pointer or host output queue is admitted as serialized state. */
typedef struct Sm17SnapshotHeader {
    uint8_t magic[8];
    uint32_t version,header_bytes;
    uint64_t payload_bytes;
    uint32_t pointer_bytes,size_t_bytes;
    uint8_t rom[32],build[32],options[32],digest[32];
} Sm17SnapshotHeader;
static const uint8_t sm17_snapshot_magic[8]={'S','M','1','7','S','N','0','1'};

void sm17_clear_bindings(Sm17State *s) {
    s->storage.bus.memory.rom=NULL;
    memset(&s->storage.bus.ports,0,sizeof(s->storage.bus.ports));
    s->storage.bus.active_cpu=NULL;
    s->storage.io.bus=NULL;
    memset(&s->storage.io.pins,0,sizeof(s->storage.io.pins));
    s->cpu.failure_reason=NULL;
    s->scheduler.bus=NULL;
    memset(&s->scheduler.receivers,0,sizeof(s->scheduler.receivers));
    memset(&s->scheduler.autojoy,0,sizeof(s->scheduler.autojoy));
    s->clock.bus=NULL; s->clock.math=NULL;
    memset(&s->clock.timeline,0,sizeof(s->clock.timeline));
    s->clock.plan=NULL; s->clock.reset_cpu=NULL; s->clock.entry.failure_reason=NULL;
    s->machine.storage=NULL; s->machine.scheduler=NULL; s->machine.clock=NULL; s->machine.cpu=NULL;
    s->ppu.bus=NULL; s->ppu.scheduler=NULL; s->ppu.wrio=NULL;
    memset(&s->ppu.downstream,0,sizeof(s->ppu.downstream));
    s->renderer.ppu=NULL; s->renderer.bus=NULL; s->renderer.scheduler=NULL;
    memset(&s->renderer.downstream,0,sizeof(s->renderer.downstream));
    s->apu.bus=NULL; s->apu.scheduler=NULL; s->apu.source.records=NULL;
    memset(&s->apu.downstream,0,sizeof(s->apu.downstream));
    memset(&s->apu.dsp,0,sizeof(s->apu.dsp));
    memset(&s->apu.static_owner,0,sizeof(s->apu.static_owner));
    s->spc.apu=NULL;
    s->dsp.apu=NULL; s->dsp.bus=NULL;
    s->input.bus=NULL; s->input.scheduler=NULL;
    s->dma.bus=NULL; s->dma.scheduler=NULL;
    memset(&s->dma.downstream,0,sizeof(s->dma.downstream));
}

void sm17_restore_bindings(Sm17State *s,const Sm17State *b) {
    s->storage.bus.memory.rom=b->storage.bus.memory.rom;
    s->storage.bus.ports=b->storage.bus.ports;
    s->storage.bus.active_cpu=NULL;
    s->storage.io.bus=b->storage.io.bus; s->storage.io.pins=b->storage.io.pins;
    s->cpu.failure_reason=NULL;
    s->scheduler.bus=b->scheduler.bus; s->scheduler.receivers=b->scheduler.receivers;
    s->scheduler.autojoy=b->scheduler.autojoy;
    s->clock.bus=b->clock.bus; s->clock.math=b->clock.math; s->clock.timeline=b->clock.timeline;
    s->clock.plan=NULL; s->clock.reset_cpu=NULL; s->clock.entry.failure_reason=NULL;
    s->machine.storage=b->machine.storage; s->machine.scheduler=b->machine.scheduler;
    s->machine.clock=b->machine.clock; s->machine.cpu=b->machine.cpu;
    s->ppu.bus=b->ppu.bus; s->ppu.scheduler=b->ppu.scheduler; s->ppu.wrio=b->ppu.wrio;
    s->ppu.downstream=b->ppu.downstream;
    s->renderer.ppu=b->renderer.ppu; s->renderer.bus=b->renderer.bus;
    s->renderer.scheduler=b->renderer.scheduler; s->renderer.downstream=b->renderer.downstream;
    s->apu.bus=b->apu.bus; s->apu.scheduler=b->apu.scheduler;
    s->apu.source.records=b->apu.source.records; s->apu.downstream=b->apu.downstream;
    s->apu.dsp=b->apu.dsp; s->apu.static_owner=b->apu.static_owner;
    s->spc.apu=b->spc.apu; s->dsp.apu=b->dsp.apu; s->dsp.bus=b->dsp.bus;
    s->input.bus=b->input.bus; s->input.scheduler=b->input.scheduler;
    s->dma.bus=b->dma.bus; s->dma.scheduler=b->dma.scheduler; s->dma.downstream=b->dma.downstream;
}

static int sm17_cpu_valid(const SmScpuState *s) {
    return s->e<=1u && s->stopped==0u && s->failure_reason==NULL &&
      (!s->e || ((s->p & (SM_P_M|SM_P_X))==(SM_P_M|SM_P_X) && (s->s & 0xff00u)==0x0100u)) &&
      (!(s->p & SM_P_X) || ((s->x|s->y)&0xff00u)==0u);
}

int sm17_snapshot_boundary(const SmCore *c) {
    const Sm17State *s;
    if(!sm17_assembled(c) || c->busy) return 0;
    s=&c->state;
    return s->storage.bus.fault.status==SM08_OK && sm17_cpu_valid(&s->cpu) &&
      !s->storage.bus.instruction_open && s->storage.bus.active_cpu==NULL &&
      !s->scheduler.advancing && !s->scheduler.transfer_advancing &&
      !s->scheduler.transfer_boundary && !s->scheduler.poll_valid &&
      !s->dma.servicing && !s->clock.active && !s->clock.reset_vector_phase &&
      s->clock.reset_cpu==NULL && s->machine.reset_phase==SM09_RESET_NONE;
}

/* Candidate is pointer-free. Validation inspects owned scalar/storage
 * values only; never call reset, bind, execute or touch a serialized pointer. */
int sm17_state_valid(const Sm17State *s) {
    unsigned i;
    uint16_t line_clocks,lines;
    if(s->storage.bus.memory.rom_size!=SM_CORE_ROM_BYTES ||
       s->storage.bus.memory.sram_dirty>1u || s->storage.bus.memory.access_started>1u ||
       s->storage.bus.wram_address>=SM08_WRAM_SIZE || s->storage.bus.memsel>1u ||
       s->storage.bus.fault.status!=SM08_OK || !sm17_cpu_valid(&s->cpu) ||
       s->storage.bus.instruction_open || s->clock.active || s->clock.reset_vector_phase ||
       s->scheduler.advancing || s->scheduler.transfer_advancing ||
       s->scheduler.transfer_boundary || s->scheduler.poll_valid || s->dma.servicing ||
       s->machine.reset_phase!=SM09_RESET_NONE) return 0;
    if(s->storage.io.math.mode>2u || s->storage.io.math.remaining>16u) return 0;
    if(s->scheduler.field>1u || s->scheduler.interlace>1u || s->scheduler.overscan>1u ||
       s->scheduler.hblank>1u || s->scheduler.vblank>1u || s->scheduler.refreshing>1u ||
       s->scheduler.smp.remainder>=SM09_SMP_DENOMINATOR ||
       s->scheduler.autojoy_step>34u || s->scheduler.autojoy_active>1u ||
       s->scheduler.autojoy_busy>1u || s->scheduler.polled_interrupt>2u) return 0;
    line_clocks=(!s->scheduler.interlace && s->scheduler.field && s->scheduler.scanline==240u)?1360u:1364u;
    lines=(uint16_t)(262u+(s->scheduler.interlace && s->scheduler.field==0u ? 1u : 0u));
    if(s->scheduler.scanline>=lines || s->scheduler.hclock>=line_clocks ||
       (s->scheduler.previous_line_clocks!=1360u && s->scheduler.previous_line_clocks!=1364u)) return 0;
    if(s->ppu.bound!=1u || s->ppu.forced_blank>1u || s->ppu.cgram_second>1u ||
       s->ppu.counter_h_second>1u || s->ppu.counter_v_second>1u ||
       s->ppu.counter_latched>1u || s->renderer.bound!=1u ||
       s->renderer.width!=256u || s->renderer.height!=224u ||
       s->renderer.ready>1u || s->renderer.field_published>1u ||
       s->renderer.object_count>32u || s->renderer.objects_valid>1u ||
       s->renderer.objects_prepared>1u || s->renderer.failure.status!=SM08_OK) return 0;
    if(s->renderer.ready && (s->renderer.published_width!=256u || s->renderer.published_height!=224u)) return 0;
    for(i=0u;i<s->renderer.object_count;++i)
        if(s->renderer.objects[i].index>=128u || s->renderer.objects[i].x>=512u ||
           (s->renderer.objects[i].size!=8u && s->renderer.objects[i].size!=16u) ||
           s->renderer.objects[i].row>=s->renderer.objects[i].size ||
           (s->renderer.objects[i].tile_mask & (uint8_t)~((1u<<(s->renderer.objects[i].size/8u))-1u))) return 0;
    if(s->input.bound!=1u || s->input.physical.present[0]>1u || s->input.physical.present[1]>1u ||
       s->input.cpu_strobe>1u || s->input.auto_strobe>1u || s->input.effective_strobe>1u ||
       s->input.effective_strobe!=(uint8_t)(s->input.cpu_strobe|s->input.auto_strobe) ||
       s->input.last_phase>34u) return 0;
    if(s->dma.active_channel!=0xffu && s->dma.active_channel>=8u) return 0;
    if(s->dma.line_pending>1u || s->dma.init_pending>1u) return 0;
    for(i=0u;i<8u;++i)
        if(s->dma.channel[i].manual_active>1u || s->dma.channel[i].finished>1u ||
           s->dma.channel[i].transfer_line>1u) return 0;
    if(s->apu.bound!=1u || (unsigned)s->apu.phase>SM12_STATIC_RUNNING ||
       s->apu.phase==SM12_FAILED || s->apu.startup_remaining>2u || s->apu.dsp_phase>=32u ||
       s->apu.smp_cycles>UINT64_MAX/2u || s->apu.completed_half!=s->apu.smp_cycles*2u ||
       s->apu.source.record_count!=1u || s->apu.source.entry!=0x0380u ||
       s->apu.source.fresh_data_per_byte!=1u || s->apu.record_index>1u ||
       (s->apu.record_open && s->apu.record_index>=s->apu.source.record_count) ||
       s->apu.record_written>4839u || s->apu.pending_mask>15u ||
       s->apu.ipl.active>1u || s->apu.ipl.length>8u || s->apu.ipl.cycle>8u ||
       s->apu.ipl.remaining>8u || s->apu.ipl.branch_taken>1u || s->apu.ipl_enabled>1u) return 0;
    for(i=0u;i<3u;++i)
        if(s->apu.timers[i].enabled>1u || s->apu.timers[i].output>15u ||
           s->apu.timers[i].prescaler>=(i==2u ? 16u : 128u)) return 0;
    if(s->spc.return_depth>256u || s->spc.active>1u ||
       s->spc.total_cycles>12u || s->spc.cycle_index>12u ||
       s->spc.cycles_remaining>s->spc.total_cycles || s->spc.branch_taken>1u) return 0;
    if(s->spc.active && (s->spc.cycles_remaining==0u ||
       (s->apu.aram[s->spc.active_pc].value==0x6fu && s->spc.return_depth==0u) ||
       (s->apu.aram[s->spc.active_pc].value==0x3fu && s->spc.return_depth>=256u))) return 0;
    if(s->dsp.bound!=1u || s->dsp.phase>=32u || s->dsp.history_index>=8u ||
       s->dsp.alternating_sample>1u || s->dsp.rate_counter>0x77ffu ||
       s->dsp.pcm_read>=SM16_PCM_CAPACITY || s->dsp.pcm_write>=SM16_PCM_CAPACITY ||
       s->dsp.pcm_count>SM16_PCM_CAPACITY ||
       (s->dsp.pcm_read+s->dsp.pcm_count)%SM16_PCM_CAPACITY!=s->dsp.pcm_write ||
       s->dsp.phase!=s->apu.dsp_phase || s->dsp.last_smp_cycle!=s->apu.smp_cycles ||
       s->dsp.phase_steps!=s->apu.smp_cycles) return 0;
    for(i=0u;i<8u;++i) {
        unsigned j;
        if(s->dsp.voice[i].decode_position>=12u || s->dsp.voice[i].brr_offset>9u ||
           s->dsp.voice[i].key_delay>5u || s->dsp.voice[i].mode>SM16_SUSTAIN ||
           s->dsp.voice[i].envelope.value<0 || s->dsp.voice[i].envelope.value>2047 ||
           s->dsp.voice[i].hidden_envelope.value < -2048 ||
           s->dsp.voice[i].hidden_envelope.value>4095) return 0;
        for(j=0u;j<12u;++j)
            if(s->dsp.voice[i].decoded[j].value < -32768 ||
               s->dsp.voice[i].decoded[j].value>32767) return 0;
    }
    return 1;
}

static int sm17_pointer_free(const Sm17State *s,Sm17State *scratch) {
    *scratch=*s;
    sm17_clear_bindings(scratch);
    return memcmp(s,scratch,sizeof(*s))==0;
}
static size_t sm17_file_size(void) { return sizeof(Sm17SnapshotHeader)+sizeof(Sm17State); }
size_t sm_core_snapshot_size(const SmCore *c) {
    /* Loading must remain available after a failed live instruction. */
    return sm17_assembled(c) && !c->busy ? sm17_file_size() : 0u;
}

static int sm17_options_digest(const SmCoreOptions *options,uint8_t digest[32]) {
    SmCoreOptions identity=*options;
    /* Initial attachment/report choices are input state, not hardware ABI.
     * Snapshot physical input itself is preserved in the15 owner payload. */
    memset(identity.pads,0,sizeof(identity.pads));
    return sm08_sha256((const uint8_t *)&identity,sizeof(identity),digest);
}

int sm_core_snapshot_save(const SmCore *c,void *destination,size_t size) {
    uint8_t *file;
    Sm17SnapshotHeader header;
    Sm17State *payload;
    int success=0;
    if(destination==NULL || size!=sm17_file_size() || !sm17_snapshot_boundary(c)) return 0;
    file=calloc(1u,size);
    if(file==NULL) return 0;
    memset(&header,0,sizeof(header));
    memcpy(header.magic,sm17_snapshot_magic,8u);
    header.version=1u; header.header_bytes=(uint32_t)sizeof(header);
    header.payload_bytes=sizeof(Sm17State);
    header.pointer_bytes=(uint32_t)sizeof(void *); header.size_t_bytes=(uint32_t)sizeof(size_t);
    memcpy(header.rom,sm08_rom_sha256,32u);
    if(!sm_core_build_identity(header.build) ||
       !sm17_options_digest(&c->options,header.options)) goto cleanup;
    memcpy(file,&header,sizeof(header));
    payload=malloc(sizeof(*payload));
    if(payload==NULL) goto cleanup;
    *payload=c->state;
    sm17_clear_bindings(payload);
    if(!sm17_state_valid(payload)) { free(payload); goto cleanup; }
    memcpy(file+sizeof(header),payload,sizeof(*payload));
    free(payload);
    if(!sm08_sha256(file,size,header.digest)) goto cleanup;
    memcpy(file,&header,sizeof(header));
    memcpy(destination,file,size);
    success=1;
cleanup:
    free(file);
    return success;
}

int sm_core_snapshot_load(SmCore *c,const void *source,size_t size) {
    Sm17SnapshotHeader header;
    Sm17State *candidate=NULL,*bindings=NULL;
    uint8_t *file=NULL,build[32]={0},options[32]={0},digest[32]={0},expected[32]={0};
    int success=0;
    /* Restore may recover a faulted live core; only public reentrancy and the
     * compiled binding graph are prerequisites, not live CPU/clock health. */
    if(!sm17_assembled(c) || c->busy || source==NULL || size!=sm17_file_size()) return 0;
    memcpy(&header,source,sizeof(header));
    if(memcmp(header.magic,sm17_snapshot_magic,8u)!=0 || header.version!=1u ||
       header.header_bytes!=sizeof(header) || header.payload_bytes!=sizeof(Sm17State) ||
       header.pointer_bytes!=sizeof(void *) || header.size_t_bytes!=sizeof(size_t) ||
       memcmp(header.rom,sm08_rom_sha256,32u)!=0 ||
       !sm_core_build_identity(build) || memcmp(header.build,build,32u)!=0 ||
       !sm17_options_digest(&c->options,options) ||
       memcmp(header.options,options,32u)!=0) return 0;
    file=malloc(size); candidate=malloc(sizeof(*candidate)); bindings=malloc(sizeof(*bindings));
    if(file==NULL || candidate==NULL || bindings==NULL) goto cleanup;
    memcpy(file,source,size);
    memcpy(expected,header.digest,32u); memset(header.digest,0,32u);
    memcpy(file,&header,sizeof(header));
    if(!sm08_sha256(file,size,digest) || memcmp(digest,expected,32u)!=0) goto cleanup;
    memcpy(candidate,file+sizeof(header),sizeof(*candidate));
    if(!sm17_pointer_free(candidate,bindings) || !sm17_state_valid(candidate)) goto cleanup;
    /* Copy only the live compiled process graph, never call owner bind/reset.
     * All rejection paths above leave guest and host state untouched. */
    *bindings=c->state;
    c->state=*candidate;
    sm17_restore_bindings(&c->state,bindings);
    success=1;
cleanup:
    free(file); free(candidate); free(bindings);
    return success;
}
