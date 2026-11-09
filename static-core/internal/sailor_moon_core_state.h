#ifndef SAILOR_MOON_CORE_STATE_H
#define SAILOR_MOON_CORE_STATE_H
#include "../include/sailor_moon_core.h"
#include "sailor_moon_machine.h"
#include "sailor_moon_renderer.h"
#include "sailor_moon_sdsp.h"
#include "sailor_moon_input.h"
#include "sailor_moon_dma.h"
#include "sailor_moon_sram.h"
#include "sailor_moon_identity.h"
#include "sailor_moon_spc700_aot.h"

/* All mutable guest owners, including in-progress SMP/DSP/renderer state.
 * Process bindings are removed/restored explicitly by snapshot.c. */
typedef struct Sm17State {
    Sm08Machine storage;
    SmScpuState cpu;
    Sm09Scheduler scheduler;
    Sm09Clock clock;
    Sm09Machine machine;
    Sm11Ppu ppu;
    Sm14Renderer renderer;
    Sm12Apu apu;
    Sm13State spc;
    Sm16Dsp dsp;
    Sm15Input input;
    Sm10Dma dma;
    uint64_t raster_deliveries,scpu_instructions;
} Sm17State;
struct SmCore {
    uint8_t *rom;
    SmCoreOptions options;
    Sm17State state;
    uint8_t busy;
};
int sm17_assembled(const SmCore *);
int sm17_snapshot_boundary(const SmCore *);
int sm17_options_valid(const SmCoreOptions *);
void sm17_clear_bindings(Sm17State *);
void sm17_restore_bindings(Sm17State *,const Sm17State *);
int sm17_state_valid(const Sm17State *);
#endif
