#include "sailor_moon_scheduler.h"

Sm08Status sm09_scheduler_dma_alignment(const Sm09Scheduler *s, uint64_t origin, uint8_t *delay) {
    uint64_t phase;
    if (s == NULL || delay == NULL || s->master_clock < origin) return SM08_ARGUMENT;
    phase = s->master_clock - origin;
    if ((phase & 1u) != 0u) return SM08_CLOCK_ABSENT;
    *delay = (uint8_t)(8u - (phase & 7u));
    return SM08_OK;
}

Sm08Status sm09_scheduler_dma_resume_delay(const Sm09Scheduler *s, uint64_t pause,
                                          uint8_t cpu_clocks, uint8_t *delay) {
    uint64_t elapsed;
    if (s == NULL || delay == NULL || s->master_clock < pause ||
        (cpu_clocks != 6u && cpu_clocks != 8u && cpu_clocks != 12u)) return SM08_ARGUMENT;
    elapsed = s->master_clock - pause;
    if ((elapsed & 1u) != 0u) return SM08_CLOCK_ABSENT;
    *delay = (uint8_t)(cpu_clocks - elapsed % cpu_clocks);
    return SM08_OK;
}
