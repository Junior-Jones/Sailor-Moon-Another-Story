#include "sailor_moon_cpu_io.h"

static Sm08Status sm08_io_read(void *context, uint16_t reg, Sm08Drive *out) {
    Sm08Io *io = (Sm08Io *)context;
    if (io == NULL || io->bus == NULL || out == NULL) return SM08_ARGUMENT;
    if (reg >= 0x4214u && reg <= 0x4217u)
        return sm08_math_read(&io->math, reg, out);
    if (reg == 0x4213u) {
        Sm08Value external = {0u, 0u};
        const uint8_t output_low = (uint8_t)((0xFFu ^ io->wrio.value) & io->wrio.known_mask);
        uint8_t input_low;
        Sm08Status status;
        if (output_low != 0xFFu) {
            if (io->pins.sample == NULL) return SM08_INPUT_ABSENT;
            status = io->pins.sample(io->pins.context, &external);
            if (status != SM08_OK) return status;
            if (io->bus->fault.status != SM08_OK) return io->bus->fault.status;
        }
        input_low = (uint8_t)((0xFFu ^ external.value) & external.known_mask);
        out->value = (uint8_t)(io->wrio.value & external.value);
        out->known_mask = (uint8_t)(output_low | input_low |
                                  (io->wrio.known_mask & external.known_mask));
        out->driven_mask = 0xFFu;
        return SM08_OK;
    }
    if (reg == 0x4201u || reg == 0x420Du || (reg >= 0x4202u && reg <= 0x4206u)) {
        out->value = 0u;
        out->known_mask = 0u;
        out->driven_mask = 0u;
        return SM08_OK;
    }
    return SM08_REGISTER;
}

static Sm08Status sm08_io_write(void *context, uint16_t reg, Sm08Value value) {
    Sm08Io *io = (Sm08Io *)context;
    if (io == NULL || io->bus == NULL) return SM08_ARGUMENT;
    if (reg >= 0x4202u && reg <= 0x4206u)
        return sm08_math_write(&io->math, reg, value);
    if (reg == 0x420Du) {
        if ((value.known_mask & 1u) == 0u) return SM08_UNKNOWN;
        io->bus->memsel = value.value & 1u;
        return SM08_OK;
    }
    if (reg == 0x4201u) {
        Sm08Status status;
        const Sm08Value previous = io->wrio;
        if (value.known_mask != 0xFFu) return SM08_UNKNOWN;
        if (io->pins.drive == NULL) return SM08_INPUT_ABSENT;
        /* Pins may already have changed when the receiver rejects a write. */
        io->wrio = value;
        status = io->pins.drive(io->pins.context, previous, value);
        if (status == SM08_OK) status = io->bus->fault.status;
        return status;
    }
    if (reg >= 0x4213u && reg <= 0x4217u) return SM08_OK;
    return SM08_REGISTER;
}

void sm08_io_init(Sm08Io *io, Sm08Bus *bus, Sm08Pins pins) {
    if (io == NULL) return;
    io->bus = bus;
    io->pins = pins;
    io->wrio.value = 0xFFu;
    io->wrio.known_mask = 0xFFu;
    sm08_math_init(&io->math);
}

Sm08Device sm08_io_device(Sm08Io *io) {
    Sm08Device device;
    device.context = io;
    device.read = sm08_io_read;
    device.write = sm08_io_write;
    return device;
}

Sm08Status sm08_machine_power_on(Sm08Machine *machine, const uint8_t *rom,
                                 size_t size, Sm08Ports ports, Sm08Pins pins) {
    Sm08Status status;
    if (machine == NULL) return SM08_ARGUMENT;
    status = sm08_bus_power_on(&machine->bus, rom, size, ports);
    if (status != SM08_OK) return status;
    sm08_io_init(&machine->io, &machine->bus, pins);
    machine->bus.ports.cpu_io = sm08_io_device(&machine->io);
    return SM08_OK;
}

Sm08Status sm08_machine_reset_latches(Sm08Machine *machine) {
    Sm08Status status;
    Sm08Fault earlier;
    const Sm08Fault clear = {SM08_OK, 8u, 0u, {0u, 0u}};
    const Sm08Value released = {0xFFu, 0xFFu};
    if (machine == NULL || machine->io.bus != &machine->bus) return SM08_ARGUMENT;
    status = sm08_memory_reset(&machine->bus.memory);
    if (status != SM08_OK) return status;
    earlier = machine->bus.fault;
    if (machine->io.wrio.value != 0xFFu || machine->io.wrio.known_mask != 0xFFu) {
        const Sm08Value previous = machine->io.wrio;
        if (machine->io.pins.drive == NULL) return SM08_INPUT_ABSENT;
        machine->io.wrio = released;
        machine->bus.fault = clear;
        status = machine->io.pins.drive(machine->io.pins.context, previous, released);
        if (status == SM08_OK) status = machine->bus.fault.status;
        if (status != SM08_OK) {
            if (earlier.status != SM08_OK) machine->bus.fault = earlier;
            return status;
        }
    }
    machine->bus.memsel = 0u;
    machine->bus.wram_address = 0u;
    machine->bus.fault = clear;
    return SM08_OK;
}
