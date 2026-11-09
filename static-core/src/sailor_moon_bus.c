#include "../internal/sailor_moon_bus.h"

Sm08Status sm08_bus_fault(Sm08Bus *bus, Sm08Status status, unsigned owner,
                          uint32_t address, Sm08Value sample) {
    if (bus == NULL) return status;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    if (status == SM08_OK) return SM08_OK;
    switch (status) {
        case SM08_CLOCK_ABSENT: owner = 9u; break;
        case SM08_DMA_ABSENT: owner = 10u; break;
        case SM08_PPU_ABSENT: owner = 11u; break;
        case SM08_APUIO_ABSENT: owner = 12u; break;
        case SM08_INPUT_ABSENT: owner = 15u; break;
        default: break;
    }
    bus->fault.status = status;
    bus->fault.owner = owner;
    bus->fault.address = address;
    bus->fault.sample = sample;
    return status;
}

Sm08Status sm08_bus_power_on(Sm08Bus *bus, const uint8_t *rom, size_t size,
                             Sm08Ports ports) {
    Sm08Status status;
    const Sm08Value unknown = {0u, 0u};
    if (bus == NULL) return SM08_ARGUMENT;
    status = sm08_memory_power_on(&bus->memory, rom, size);
    if (status != SM08_OK) return status;
    bus->ports = ports;
    bus->mdr = unknown;
    bus->fault.status = SM08_OK;
    bus->fault.owner = 8u;
    bus->fault.address = 0u;
    bus->fault.sample = unknown;
    bus->wram_address = 0u;
    bus->memsel = 0u;
    bus->active_cpu = NULL;
    bus->instruction_open = 0u;
    return SM08_OK;
}

static Sm08Device *sm08_device(Sm08Bus *bus, Sm08Kind kind, Sm08Status *absent) {
    switch (kind) {
        case SM08_PPU: *absent = SM08_PPU_ABSENT; return &bus->ports.ppu;
        case SM08_APUIO: *absent = SM08_APUIO_ABSENT; return &bus->ports.apuio;
        case SM08_DMA_IO: *absent = SM08_DMA_ABSENT; return &bus->ports.dma;
        case SM08_INPUT_IO: *absent = SM08_INPUT_ABSENT; return &bus->ports.input;
        case SM08_SCHEDULER_IO: *absent = SM08_CLOCK_ABSENT; return &bus->ports.scheduler;
        case SM08_CPU_IO: *absent = SM08_IO_ABSENT; return &bus->ports.cpu_io;
        default: *absent = SM08_REGISTER; return NULL;
    }
}

Sm08Status sm08_bus_sample(Sm08Bus *bus, uint32_t address, Sm08Value *out) {
    Sm08Region region;
    Sm08Cell cell;
    Sm08Value value;
    Sm08Drive drive = {0u, 0u, 0u};
    Sm08Device *device;
    Sm08Status status;
    uint8_t floating;
    if (bus == NULL || out == NULL || !sm08_decode(address, &region)) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    bus->memory.access_started = 1u;
    value = bus->mdr;
    switch (region.kind) {
        case SM08_ROM: case SM08_WRAM: case SM08_SRAM:
            status = sm08_memory_read(&bus->memory, address, &cell);
            if (status != SM08_OK) return sm08_bus_fault(bus, status, 8u, address, value);
            value.value = cell.value;
            value.known_mask = cell.known ? 0xFFu : 0u;
            break;
        case SM08_WRAM_PORT:
            if (region.offset == 0x2180u) {
                if (bus->wram_address >= SM08_WRAM_SIZE)
                    return sm08_bus_fault(bus, SM08_STORAGE, 8u, address, value);
                status = sm08_memory_read(&bus->memory, 0x7E0000u + bus->wram_address, &cell);
                if (status != SM08_OK) return sm08_bus_fault(bus, status, 8u, address, value);
                value.value = cell.value;
                value.known_mask = cell.known ? 0xFFu : 0u;
                bus->wram_address = (bus->wram_address + 1u) & 0x1FFFFu;
            }
            break;
        case SM08_OPEN_EXTERNAL: case SM08_OPEN_INTERNAL:
            break;
        default:
            device = sm08_device(bus, region.kind, &status);
            if (device == NULL || device->read == NULL)
                return sm08_bus_fault(bus, status, region.owner, address, value);
            status = device->read(device->context, (uint16_t)region.offset, &drive);
            if (status != SM08_OK) return sm08_bus_fault(bus, status, region.owner, address, value);
            if (bus->fault.status != SM08_OK) return bus->fault.status;
            floating = (uint8_t)~drive.driven_mask;
            value.value = (uint8_t)((drive.value & drive.driven_mask) | (value.value & floating));
            value.known_mask = (uint8_t)((drive.known_mask & drive.driven_mask) |
                                          (value.known_mask & floating));
            break;
    }
    /* Selected external-MDR contract: internal register samples do not
     * manufacture an external fully driven retained byte. */
    if (!region.internal_io) bus->mdr = value;
    *out = value;
    return SM08_OK;
}

Sm08Status sm08_bus_commit(Sm08Bus *bus, uint32_t address, Sm08Value value) {
    Sm08Region region;
    Sm08Cell cell;
    Sm08Device *device;
    Sm08Status status;
    uint8_t consumed;
    if (bus == NULL || !sm08_decode(address, &region)) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    bus->memory.access_started = 1u;
    cell.value = value.value;
    cell.known = value.known_mask == 0xFFu;
    switch (region.kind) {
        case SM08_ROM: case SM08_WRAM: case SM08_SRAM:
            status = sm08_memory_write(&bus->memory, address, cell);
            if (status != SM08_OK) return sm08_bus_fault(bus, status, 8u, address, value);
            break;
        case SM08_WRAM_PORT:
            if (region.offset == 0x2180u) {
                if (bus->wram_address >= SM08_WRAM_SIZE)
                    return sm08_bus_fault(bus, SM08_STORAGE, 8u, address, value);
                status = sm08_memory_write(&bus->memory, 0x7E0000u + bus->wram_address, cell);
                if (status != SM08_OK) return sm08_bus_fault(bus, status, 8u, address, value);
                bus->wram_address = (bus->wram_address + 1u) & 0x1FFFFu;
            } else {
                consumed = region.offset == 0x2183u ? 1u : 0xFFu;
                if ((value.known_mask & consumed) != consumed)
                    return sm08_bus_fault(bus, SM08_UNKNOWN, 8u, address, value);
                if (region.offset == 0x2181u)
                    bus->wram_address = (bus->wram_address & 0x1FF00u) | value.value;
                else if (region.offset == 0x2182u)
                    bus->wram_address = (bus->wram_address & 0x100FFu) | ((uint32_t)value.value << 8u);
                else
                    bus->wram_address = (bus->wram_address & 0xFFFFu) | ((uint32_t)(value.value & 1u) << 16u);
            }
            break;
        case SM08_OPEN_EXTERNAL: case SM08_OPEN_INTERNAL:
            break;
        default:
            device = sm08_device(bus, region.kind, &status);
            if (device == NULL || device->write == NULL)
                return sm08_bus_fault(bus, status, region.owner, address, value);
            status = device->write(device->context, (uint16_t)region.offset, value);
            if (status != SM08_OK) return sm08_bus_fault(bus, status, region.owner, address, value);
            if (bus->fault.status != SM08_OK) return bus->fault.status;
            break;
    }
    if (!region.internal_io) bus->mdr = value;
    return SM08_OK;
}

Sm08Status sm08_bus_known(Sm08Bus *bus, uint32_t address, Sm08Value value, uint8_t *out) {
    if (bus == NULL || out == NULL) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    if (value.known_mask != 0xFFu) return sm08_bus_fault(bus, SM08_UNKNOWN, 8u, address, value);
    *out = value.value;
    return SM08_OK;
}

Sm08Status sm08_bus_reset_vector(Sm08Bus *bus, uint16_t *out) {
    const Sm08Value unknown = {0u, 0u};
    uint8_t bytes[2];
    Sm08Status status;
    unsigned lane;
    if (bus == NULL || out == NULL) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    if (bus->ports.clock.reset_read == NULL)
        return sm08_bus_fault(bus, SM08_CLOCK_ABSENT, 9u, 0xFFFCu, unknown);
    for (lane = 0u; lane != 2u; ++lane) {
        status = bus->ports.clock.reset_read(bus->ports.clock.context, bus, 0xFFFCu + lane, &bytes[lane]);
        if (status != SM08_OK) return sm08_bus_fault(bus, status, 9u, 0xFFFCu + lane, unknown);
        if (bus->fault.status != SM08_OK) return bus->fault.status;
    }
    *out = (uint16_t)((uint16_t)bytes[0] | ((uint16_t)bytes[1] << 8u));
    return SM08_OK;
}

static int sm08_guard(void *context, const SmScpuState *cpu,
                       const SmStaticFetch *fetch, const uint8_t *expected) {
    Sm08Bus *bus = context;
    Sm08Cell cell;
    const Sm08Value unknown = {0u, 0u};
    Sm08Status status;
    uint32_t address;
    size_t lane;
    if (bus == NULL || cpu == NULL || fetch == NULL || expected == NULL) return 0;
    if (bus->fault.status != SM08_OK) return 0;
    /* sm_scpu_guard_code obtained this descriptor from the sole generated
       registry immediately before invoking this private callback.  Repeating
       that large registry lookup here made every instruction validate twice. */
    if (bus->instruction_open || fetch->guard_count == 0u || fetch->guard_count > 4u) {
        sm08_bus_fault(bus, SM08_GUARD, 8u, sm_scpu_address(cpu), unknown);
        return 0;
    }
    if (fetch->executable_epoch &&
        (fetch->guard_count != 4u || expected[0] != 0x54u || expected[1] != 0u ||
         expected[2] != 0u || expected[3] != 0x60u)) {
        sm08_bus_fault(bus, SM08_GUARD, 8u, fetch->guard_address, unknown);
        return 0;
    }
    for (lane = 0u; lane < fetch->guard_count; ++lane) {
        if (!(fetch->immutable_byte_mask & (1u << lane))) continue;
        address = (fetch->guard_address & 0xFF0000u) | ((fetch->guard_address + (uint32_t)lane) & 0xFFFFu);
        if (sm08_memory_peek(&bus->memory, address, &cell) != SM08_OK ||
            !cell.known || cell.value != expected[lane]) {
            sm08_bus_fault(bus, SM08_GUARD, 8u, address, unknown);
            return 0;
        }
    }
    if (bus->ports.clock.begin == NULL) {
        sm08_bus_fault(bus, SM08_CLOCK_ABSENT, 9u, fetch->fetch_address, unknown);
        return 0;
    }
    bus->active_cpu = cpu;
    bus->instruction_open = 1u;
    status = bus->ports.clock.begin(bus->ports.clock.context, bus, cpu, fetch, expected);
    if (status != SM08_OK) sm08_bus_fault(bus, status, 9u, fetch->fetch_address, unknown);
    return status == SM08_OK && bus->fault.status == SM08_OK;
}

static int sm08_read(void *context, uint32_t address, uint8_t *out) {
    Sm08Bus *bus = context;
    Sm08Status status;
    const Sm08Value unknown = {0u, 0u};
    if (bus == NULL || out == NULL || bus->fault.status != SM08_OK) return 0;
    if (!bus->instruction_open || bus->active_cpu == NULL || bus->ports.clock.read == NULL) {
        sm08_bus_fault(bus, SM08_CLOCK_ABSENT, 9u, address, unknown);
        return 0;
    }
    status = bus->ports.clock.read(bus->ports.clock.context, bus, bus->active_cpu, address, out);
    if (status != SM08_OK) sm08_bus_fault(bus, status, 9u, address, unknown);
    return status == SM08_OK && bus->fault.status == SM08_OK;
}

static int sm08_write(void *context, uint32_t address, uint8_t value) {
    Sm08Bus *bus = context;
    Sm08Status status;
    const Sm08Value sample = {value, 0xFFu};
    if (bus == NULL || bus->fault.status != SM08_OK) return 0;
    if (!bus->instruction_open || bus->active_cpu == NULL || bus->ports.clock.write == NULL) {
        sm08_bus_fault(bus, SM08_CLOCK_ABSENT, 9u, address, sample);
        return 0;
    }
    status = bus->ports.clock.write(bus->ports.clock.context, bus, bus->active_cpu, address, value);
    if (status != SM08_OK) sm08_bus_fault(bus, status, 9u, address, sample);
    return status == SM08_OK && bus->fault.status == SM08_OK;
}

static int sm08_finish(void *context, const SmScpuState *cpu, uint32_t cycles) {
    Sm08Bus *bus = context;
    Sm08Status status;
    const Sm08Value unknown = {0u, 0u};
    if (bus == NULL || cpu == NULL || bus->fault.status != SM08_OK) return 0;
    if (!bus->instruction_open || bus->active_cpu != cpu || bus->ports.clock.finish == NULL) {
        sm08_bus_fault(bus, SM08_CLOCK_ABSENT, 9u, sm_scpu_address(cpu), unknown);
        return 0;
    }
    status = bus->ports.clock.finish(bus->ports.clock.context, bus, cpu, cycles);
    if (status != SM08_OK) sm08_bus_fault(bus, status, 9u, sm_scpu_address(cpu), unknown);
    if (status != SM08_OK || bus->fault.status != SM08_OK) return 0;
    bus->instruction_open = 0u;
    bus->active_cpu = NULL;
    return 1;
}

SmScpuBus sm08_bus_cpu_view(Sm08Bus *bus) {
    SmScpuBus view;
    view.opaque = bus;
    view.guard_code = sm08_guard;
    view.read8 = sm08_read;
    view.write8 = sm08_write;
    view.finish_instruction = sm08_finish;
    return view;
}
