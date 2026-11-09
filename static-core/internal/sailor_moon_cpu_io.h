#ifndef SAILOR_MOON_CPU_IO_H
#define SAILOR_MOON_CPU_IO_H

#include "sailor_moon_bus.h"
#include "sailor_moon_math.h"

typedef struct Sm08Pins {
    void *context;
    Sm08Status (*sample)(void *, Sm08Value *);
    Sm08Status (*drive)(void *, Sm08Value prior, Sm08Value next);
} Sm08Pins;

typedef struct Sm08Io {
    Sm08Bus *bus;
    Sm08Math math;
    Sm08Value wrio;
    Sm08Pins pins;
} Sm08Io;

typedef struct Sm08Machine {
    Sm08Bus bus;
    Sm08Io io;
} Sm08Machine;

void sm08_io_init(Sm08Io *, Sm08Bus *, Sm08Pins);
Sm08Device sm08_io_device(Sm08Io *);
Sm08Status sm08_machine_power_on(Sm08Machine *, const uint8_t *, size_t,
                                Sm08Ports, Sm08Pins);
/* 08 reset-line latches only: no CPU/vector cycles or device clock. Storage,
 * math and MDR remain intact. A failed pin release retains partial effects
 * and the earlier first diagnostic; later latches are not falsely reset.
 * Caller is quiescent, or09 owns retiring/aborting any active access. This
 * function does not clear clock/instruction callback plumbing. */
Sm08Status sm08_machine_reset_latches(Sm08Machine *);

#endif
