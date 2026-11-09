#include "sailor_moon_input.h"
#include <string.h>

static int sm15_attached(const Sm15Input *in) {
    return in != NULL && in->bus != NULL && in->scheduler != NULL &&
           in->scheduler->bus == in->bus;
}

static Sm15Word sm15_report(Sm15Word input) {
    Sm15Word out;
    out.value = input.value & SM15_STANDARD_PAD_MASK;
    out.known_mask = (uint16_t)(input.known_mask | 0x000fu);
    return out;
}

static void sm15_latch_port(Sm15Input *in, unsigned port) {
    in->serial_shift[port] = sm15_report(in->physical.report[port]);
}

static void sm15_latch(Sm15Input *in) {
    sm15_latch_port(in, 0u);
    sm15_latch_port(in, 1u);
}

static void sm15_strobe(Sm15Input *in) {
    in->effective_strobe = (uint8_t)((in->cpu_strobe | in->auto_strobe) & 1u);
    if (in->effective_strobe != 0u) sm15_latch(in);
}

/* One simultaneous Data1/Data2 sample and one physical port clock. The fixed
 * unconnected secondary line is independent of attachment/report knownness. */
static Sm08Value sm15_serial(Sm15Input *in, unsigned port) {
    Sm08Value out = {0u, 3u};
    if (in->effective_strobe != 0u) sm15_latch_port(in, port);
    if (in->physical.present[port] != 0u) {
        out.value = (uint8_t)((in->serial_shift[port].value >> 15u) & 1u);
        out.known_mask = (uint8_t)(2u | ((in->serial_shift[port].known_mask >> 15u) & 1u));
        if (in->effective_strobe == 0u) {
            in->serial_shift[port].value = (uint16_t)((in->serial_shift[port].value << 1u) | 1u);
            in->serial_shift[port].known_mask = (uint16_t)((in->serial_shift[port].known_mask << 1u) | 1u);
        }
    }
    ++in->serial_reads[port];
    return out;
}

static void sm15_clear_guest(Sm15Input *in) {
    unsigned i;
    in->cpu_strobe = 0u; in->auto_strobe = 0u; in->effective_strobe = 0u;
    for (i = 0u; i < 4u; ++i) {
        in->auto_result[i] = (Sm15Word){0u, 0xffffu};
        in->sampled_serial[i] = (Sm08Value){0u, 1u};
    }
    sm15_latch(in);
}

Sm08Status sm15_input_power_on(Sm15Input *in, Sm08Bus *bus,
                              Sm09Scheduler *scheduler, const Sm15Physical *physical) {
    Sm15Physical initial;
    if (in == NULL || bus == NULL || scheduler == NULL || physical == NULL ||
        scheduler->bus != bus || physical->present[0] > 1u || physical->present[1] > 1u)
        return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    initial = *physical;
    memset(in, 0, sizeof(*in));
    in->bus = bus; in->scheduler = scheduler;
    in->physical = initial;
    in->physical.report[0] = sm15_report(initial.report[0]);
    in->physical.report[1] = sm15_report(initial.report[1]);
    sm15_clear_guest(in);
    return SM08_OK;
}

Sm08Status sm15_input_cpu_reset(Sm15Input *in) {
    if (!sm15_attached(in) || in->scheduler->autojoy_active != 0u) return SM08_ARGUMENT;
    if (in->bus->fault.status != SM08_OK) return in->bus->fault.status;
    sm15_clear_guest(in);
    return SM08_OK;
}

Sm08Status sm15_input_set_report(Sm15Input *in, unsigned port, Sm15Word report) {
    if (!sm15_attached(in) || port >= 2u) return SM08_ARGUMENT;
    if (in->bus->fault.status != SM08_OK) return in->bus->fault.status;
    if (in->report_sequence == UINT64_MAX) return SM08_GUARD;
    in->physical.report[port] = sm15_report(report);
    ++in->report_sequence;
    if (in->effective_strobe != 0u) sm15_latch_port(in, port);
    return SM08_OK;
}

Sm08Status sm15_input_set_present(Sm15Input *in, unsigned port, uint8_t present) {
    if (!sm15_attached(in) || port >= 2u || present > 1u) return SM08_ARGUMENT;
    if (in->bus->fault.status != SM08_OK) return in->bus->fault.status;
    if (in->report_sequence == UINT64_MAX) return SM08_GUARD;
    in->physical.present[port] = present;
    ++in->report_sequence;
    if (in->effective_strobe != 0u) sm15_latch_port(in, port);
    return SM08_OK;
}

Sm08Status sm15_input_result(const Sm15Input *in, unsigned index, Sm15Word *out) {
    if (!sm15_attached(in) || out == NULL || index >= 4u) return SM08_ARGUMENT;
    if (in->bus->fault.status != SM08_OK) return in->bus->fault.status;
    *out = in->auto_result[index];
    return SM08_OK;
}

static Sm08Status sm15_read(void *context, uint16_t reg, Sm08Drive *out) {
    Sm15Input *in = context;
    Sm08Value sample = {0u, 0u};
    unsigned index = 0u, shift = 0u;
    if (!sm15_attached(in) || out == NULL) return SM08_ARGUMENT;
    if (in->bus->fault.status != SM08_OK) return in->bus->fault.status;
    if (reg >= 0x4218u && reg <= 0x421fu) {
        index = (reg - 0x4218u) / 2u;
        shift = (reg & 1u) != 0u ? 8u : 0u;
        out->value = (uint8_t)(in->auto_result[index].value >> shift);
        out->driven_mask = 0xffu;
        out->known_mask = (uint8_t)(in->auto_result[index].known_mask >> shift);
        return SM08_OK;
    }
    if (reg != 0x4016u && reg != 0x4017u) return SM08_REGISTER;
    sample = sm15_serial(in, reg == 0x4016u ? 0u : 1u);
    out->value = sample.value; out->driven_mask = 3u; out->known_mask = sample.known_mask;
    if (reg == 0x4017u) {
        out->value |= 0x1cu; out->driven_mask |= 0x1cu; out->known_mask |= 0x1cu;
    }
    return SM08_OK;
}

static Sm08Status sm15_write(void *context, uint16_t reg, Sm08Value value) {
    Sm15Input *in = context;
    if (!sm15_attached(in)) return SM08_ARGUMENT;
    if (in->bus->fault.status != SM08_OK) return in->bus->fault.status;
    if (reg != 0x4016u) return SM08_REGISTER;
    if ((value.known_mask & 1u) == 0u) return SM08_UNKNOWN;
    in->cpu_strobe = value.value & 1u;
    sm15_strobe(in);
    return SM08_OK;
}

Sm08Device sm15_input_device(Sm15Input *in) {
    Sm08Device device = {in, sm15_read, sm15_write};
    return device;
}

static Sm08Status sm15_phase(void *context, Sm08Bus *bus, uint64_t master,
                             uint8_t step, uint8_t enabled) {
    Sm15Input *in = context;
    Sm08Value first = {0u, 0u}, second = {0u, 0u};
    unsigned i;
    if (!sm15_attached(in) || bus != in->bus || step > 34u || enabled > 1u) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    in->last_phase_clock = master; in->last_phase = step;
    if (!enabled) {
        in->auto_strobe = 0u; sm15_strobe(in);
        return SM08_OK;
    }
    if (step == 0u) {
        in->auto_strobe = 1u; sm15_strobe(in);
    } else if (step == 1u) {
        for (i = 0u; i < 4u; ++i) {
            in->auto_result[i] = (Sm15Word){0u, 0xffffu};
            in->sampled_serial[i] = (Sm08Value){0u, 1u};
        }
    } else if (step == 2u) {
        in->auto_strobe = 0u; sm15_strobe(in);
    } else if ((step & 1u) != 0u) {
        first = sm15_serial(in, 0u); second = sm15_serial(in, 1u);
        in->sampled_serial[0] = (Sm08Value){(uint8_t)(first.value & 1u), (uint8_t)(first.known_mask & 1u)};
        in->sampled_serial[1] = (Sm08Value){(uint8_t)(second.value & 1u), (uint8_t)(second.known_mask & 1u)};
        in->sampled_serial[2] = (Sm08Value){(uint8_t)((first.value >> 1u) & 1u), (uint8_t)((first.known_mask >> 1u) & 1u)};
        in->sampled_serial[3] = (Sm08Value){(uint8_t)((second.value >> 1u) & 1u), (uint8_t)((second.known_mask >> 1u) & 1u)};
        ++in->autojoy_samples;
    } else {
        for (i = 0u; i < 4u; ++i) {
            in->auto_result[i].value = (uint16_t)((in->auto_result[i].value << 1u) | (in->sampled_serial[i].value & 1u));
            in->auto_result[i].known_mask = (uint16_t)((in->auto_result[i].known_mask << 1u) | (in->sampled_serial[i].known_mask & 1u));
        }
    }
    return SM08_OK;
}

static Sm08Status sm15_abort(void *context, Sm08Bus *bus, uint64_t master) {
    Sm15Input *in = context;
    (void)master;
    if (!sm15_attached(in) || in->bus != bus) return SM08_ARGUMENT;
    if (bus->fault.status != SM08_OK) return bus->fault.status;
    in->auto_strobe = 0u; sm15_strobe(in);
    return SM08_OK;
}

Sm09AutoJoyPort sm15_input_autojoy_port(Sm15Input *in) {
    Sm09AutoJoyPort port = {in, sm15_phase, sm15_abort};
    return port;
}

Sm08Status sm15_input_bind(Sm15Input *in) {
    Sm08Status status;
    if (!sm15_attached(in) || in->bound || in->scheduler->advancing != 0u ||
        in->scheduler->master_clock != 0u || in->scheduler->autojoy_active != 0u ||
        in->bus->ports.input.read != NULL || in->bus->ports.input.write != NULL ||
        in->scheduler->autojoy.phase != NULL || in->scheduler->autojoy.abort != NULL) return SM08_ARGUMENT;
    if (in->bus->fault.status != SM08_OK) return in->bus->fault.status;
    status = sm09_scheduler_autojoy_bind(in->scheduler, sm15_input_autojoy_port(in));
    if (status != SM08_OK) return status;
    in->bus->ports.input = sm15_input_device(in);
    in->bound = 1u;
    return SM08_OK;
}
