#ifndef SAILOR_MOON_SCHEDULER_H
#define SAILOR_MOON_SCHEDULER_H
#include "sailor_moon_clock_port.h"
#include "sailor_moon_clock_domain.h"

typedef enum Sm09RasterEvent {
    SM09_RASTER_LINE_BEGIN, SM09_RASTER_FIELD_TOGGLE,
    SM09_RASTER_HBLANK_BEGIN, SM09_RASTER_HBLANK_END,
    SM09_RASTER_VBLANK_BEGIN, SM09_RASTER_VBLANK_END,
    SM09_RASTER_NMI_FLAG_SET, SM09_RASTER_NMI_FLAG_CLEAR,
    SM09_RASTER_NMI_ASSERT, SM09_RASTER_REFRESH_BEGIN,
    SM09_RASTER_REFRESH_END, SM09_RASTER_IRQ_ASSERT,
    SM09_RASTER_HDMA_INIT_REQUEST, SM09_RASTER_HDMA_LINE_REQUEST
} Sm09RasterEvent;
typedef struct Sm09Scheduler Sm09Scheduler;
typedef struct Sm09Receivers {
    void *context;
    Sm08Status (*smp_sync)(void *, Sm08Bus *, uint64_t target_cycles);
    Sm08Status (*raster_event)(void *, Sm08Bus *, const Sm09Scheduler *, Sm09RasterEvent);
    Sm08Status (*cpu_boundary)(void *, Sm08Bus *, const Sm09Scheduler *,
                              uint8_t kind, uint32_t address, uint8_t clocks);
} Sm09Receivers;
typedef struct Sm09AutoJoyPort {
    void *context;
    Sm08Status (*phase)(void *, Sm08Bus *, uint64_t master, uint8_t step, uint8_t enabled);
    Sm08Status (*abort)(void *, Sm08Bus *, uint64_t master);
} Sm09AutoJoyPort;

struct Sm09Scheduler {
    Sm08Bus *bus;
    Sm09Receivers receivers;
    Sm09SmpJoin smp;
    uint64_t master_clock, completed_fields;
    uint16_t hclock, scanline, processed_events, previous_line_clocks;
    uint8_t field, interlace, overscan, hblank, vblank, refreshing;
    uint8_t advancing, smp_started;
    uint16_t htime, vtime, htime_known, vtime_known;
    uint8_t nmitimen, nmi_flag, nmi_line, nmi_edge_latched, nmi_pending;
    uint8_t irq_flag, irq_flag_known, irq_line, irq_level, irq_wait_ticks;
    uint8_t irq_phase_valid;
    uint16_t irq_hcounter, irq_vcounter;
    uint64_t irq_phase_clock, irq_assert_clock;
    uint8_t external_irq, poll_valid, polled_interrupt;
    uint32_t poll_context_key;
    Sm09AutoJoyPort autojoy;
    uint64_t autojoy_start_clock, autojoy_last_clock, autojoy_phase_origin, autojoy_next_clock;
    uint8_t autojoy_active, autojoy_field_claimed, autojoy_step, autojoy_effects, autojoy_busy;
    uint8_t transfer_boundary, transfer_advancing;
};

/* Cold phase0; mandatory receivers checked before modifying output. No CPU
 * reset, device startup, math pulse or bus access is performed here. */
Sm08Status sm09_scheduler_cold(Sm09Scheduler *, Sm08Bus *, Sm09Receivers);
Sm09TimelinePort sm09_scheduler_timeline(Sm09Scheduler *);
Sm08Device sm09_scheduler_register_port(Sm09Scheduler *);
Sm08Status sm09_scheduler_advance_wall(Sm09Scheduler *, uint32_t);
/* Available only inside the declared CPU-boundary receiver. Refresh drains
 * wall time without consuming transfer progress, including at its endpoint. */
Sm08Status sm09_scheduler_transfer_advance(Sm09Scheduler *, uint32_t);
Sm08Status sm09_scheduler_dma_alignment(const Sm09Scheduler *, uint64_t, uint8_t *);
Sm08Status sm09_scheduler_dma_resume_delay(const Sm09Scheduler *, uint64_t, uint8_t, uint8_t *);
/* Preserves absolute time/domain remainder/geometry/unforced timers/externalIRQ. */
Sm08Status sm09_scheduler_reset_cpu_latches(Sm09Scheduler *);
Sm08Status sm09_scheduler_autojoy_bind(Sm09Scheduler *, Sm09AutoJoyPort);
Sm08Status sm09_scheduler_autojoy_tick(Sm09Scheduler *);
Sm08Status sm09_scheduler_autojoy_abort(Sm09Scheduler *);
uint16_t sm09_scheduler_line_clocks(const Sm09Scheduler *);
uint16_t sm09_scheduler_dot(const Sm09Scheduler *);
Sm08Status sm09_scheduler_irq_match(const Sm09Scheduler *, uint8_t *);
Sm08Status sm09_scheduler_irq_tick(Sm09Scheduler *);
void sm09_scheduler_update_nmi_line(Sm09Scheduler *);
/* Consume the staged poll only. Machine owns actual vector/stack entry. */
Sm08Status sm09_scheduler_take_interrupt(Sm09Scheduler *, uint8_t *);
/* Shared sticky-fault boundary; callers retain earlier state/effects. */
Sm08Status sm09_scheduler_fault(Sm09Scheduler *, Sm08Status, unsigned owner);
#endif
