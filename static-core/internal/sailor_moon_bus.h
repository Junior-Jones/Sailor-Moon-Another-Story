#ifndef SAILOR_MOON_BUS_H
#define SAILOR_MOON_BUS_H
#include "sailor_moon_memory.h"
#include "sailor_moon_scpu.h"

typedef struct Sm08Bus Sm08Bus;
typedef struct Sm08Device {
    void *context;
    Sm08Status (*read)(void *, uint16_t, Sm08Drive *);
    Sm08Status (*write)(void *, uint16_t, Sm08Value);
} Sm08Device;

/* 09 owns real event ordering, every bus/internal arithmetic pulse, and the
 * sample/commit point. begin consumes the registered static descriptor, not
 * guest opcode decoding. It must bind executable-RAM activation/real frame to
 * the existing06 source selector; a metadata peek is not that proof or a fetch.
 * Deferred operands are consumed once by the subsequent body read callbacks.
 * finish validates actual consumed cycles against declared_cycles; it must
 * not pad an instruction with anonymous clocks. No default timing is supplied.
 */
typedef struct Sm08Clock {
    void *context;
    Sm08Status (*begin)(void *, Sm08Bus *, const SmScpuState *,
                        const SmStaticFetch *, const uint8_t *);
    Sm08Status (*read)(void *, Sm08Bus *, const SmScpuState *, uint32_t, uint8_t *);
    Sm08Status (*write)(void *, Sm08Bus *, const SmScpuState *, uint32_t, uint8_t);
    Sm08Status (*finish)(void *, Sm08Bus *, const SmScpuState *, uint32_t declared_cycles);
    Sm08Status (*reset_read)(void *, Sm08Bus *, uint32_t, uint8_t *);
} Sm08Clock;

typedef struct Sm08Ports {
    Sm08Device ppu, apuio, dma, input, scheduler, cpu_io;
    Sm08Clock clock;
} Sm08Ports;

typedef struct Sm08Fault {
    Sm08Status status;
    unsigned owner;
    uint32_t address;
    Sm08Value sample;
} Sm08Fault;

struct Sm08Bus {
    Sm08Memory memory;
    Sm08Ports ports;
    Sm08Value mdr;
    Sm08Fault fault;
    uint32_t wram_address;
    uint8_t memsel;
    /* Pointer valid only during a source instruction. This is callback
     * plumbing, not a CPU context-key field or a synthetic stack/frame token. */
    const SmScpuState *active_cpu;
    uint8_t instruction_open;
};

Sm08Status sm08_bus_power_on(Sm08Bus *, const uint8_t *, size_t, Sm08Ports);
Sm08Status sm08_bus_fault(Sm08Bus *, Sm08Status, unsigned, uint32_t, Sm08Value);
/* Untimed raw access is the sole storage/MMIO implementation. Only the09
 * sample/commit receiver and scoped boundary qualifications call these. */
Sm08Status sm08_bus_sample(Sm08Bus *, uint32_t, Sm08Value *);
Sm08Status sm08_bus_commit(Sm08Bus *, uint32_t, Sm08Value);
Sm08Status sm08_bus_known(Sm08Bus *, uint32_t, Sm08Value, uint8_t *);
Sm08Status sm08_bus_reset_vector(Sm08Bus *, uint16_t *);
SmScpuBus sm08_bus_cpu_view(Sm08Bus *);
#endif
