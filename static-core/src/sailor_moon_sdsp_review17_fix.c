#include "sailor_moon_sdsp.h"
#include "sailor_moon_spc700_aot.h"
#include <string.h>

/* Fixed hardware coefficients are independently materialized from the
 * attributed primary census, not another project's DSP implementation. */
#include "sailor_moon_sdsp_gaussian.h"

static const uint16_t sm16_period[32] = {
    0u,2048u,1536u,1280u,1024u,768u,640u,512u,384u,320u,256u,192u,
    160u,128u,96u,80u,64u,48u,40u,32u,24u,20u,16u,12u,10u,8u,6u,5u,4u,3u,2u,1u
};
static const uint16_t sm16_rate_offset[32] = {
    0u,0u,1040u,536u,0u,1040u,536u,0u,1040u,536u,0u,1040u,536u,0u,1040u,536u,
    0u,1040u,536u,0u,1040u,536u,0u,1040u,536u,0u,1040u,536u,0u,1040u,0u,0u
};

static int sm16_attached(const Sm16Dsp *d) {
    return d != NULL && d->apu != NULL && d->bus != NULL && d->apu->bus == d->bus;
}

static Sm08Status sm16_fault(Sm16Dsp *d, Sm08Status status, uint32_t address, Sm08Value v) {
    return sm08_bus_fault(d->bus, status, 16u, address, v);
}

static int sm16_known(Sm08Value v, unsigned mask) {
    return (v.known_mask & mask) == mask;
}

static Sm16Scalar sm16_scalar(int32_t value, unsigned known) {
    Sm16Scalar s = {value, (uint8_t)(known != 0u)};
    return s;
}

static int32_t sm16_asr(int32_t value, unsigned bits) {
    int64_t magnitude;
    if (bits == 0u) return value;
    if (value >= 0) return value / (int32_t)(1u << bits);
    magnitude = -(int64_t)value;
    return (int32_t)(-((magnitude + ((INT64_C(1) << bits) - 1)) / (INT64_C(1) << bits)));
}

static int32_t sm16_clamp(int32_t value) {
    if (value > 32767) return 32767;
    if (value < -32768) return -32768;
    return value;
}

static int32_t sm16_wrap16(int32_t value) {
    uint32_t bits = (uint32_t)value & 65535u;
    return bits >= 32768u ? (int32_t)bits - 65536 : (int32_t)bits;
}

static int32_t sm16_even(int32_t value) {
    return sm16_wrap16((int32_t)((uint32_t)sm16_clamp(value) & 65534u));
}

static Sm08Value sm16_reg(const Sm16Dsp *d, unsigned index) {
    return d->registers[index & 127u];
}

static Sm08Value sm16_aram(Sm16Dsp *d, Sm16Address address) {
    Sm08Value v = {0u, 0u};
    ++d->aram_reads;
    if (address.known) v = d->apu->aram[address.value];
    return v;
}

static Sm16Address sm16_add_address(Sm16Address a, unsigned amount) {
    a.value = (uint16_t)(a.value + amount);
    return a;
}

static Sm16Scalar sm16_scale(Sm16Scalar sample, Sm08Value gain, unsigned bits) {
    int32_t signed_gain = gain.value >= 128u ? (int32_t)gain.value - 256 : gain.value;
    unsigned known_gain = sm16_known(gain, 255u);
    unsigned known = (sample.known && known_gain) || (sample.known && sample.value == 0) ||
                     (known_gain && signed_gain == 0);
    return sm16_scalar(sm16_asr(sample.value * signed_gain, bits), known);
}

static Sm16Scalar sm16_sum(Sm16Scalar a, Sm16Scalar b) {
    return sm16_scalar(sm16_clamp(a.value + b.value), a.known && b.known);
}

static unsigned sm16_rate(const Sm16Dsp *d, unsigned rate) {
    rate &= 31u;
    return rate != 0u && ((unsigned)d->rate_counter + sm16_rate_offset[rate]) % sm16_period[rate] == 0u;
}

static void sm16_envelope(Sm16Dsp *d, unsigned index) {
    Sm16Voice *v = &d->voice[index];
    Sm08Value second = sm16_reg(d, index * 16u + 6u);
    Sm08Value gain = sm16_reg(d, index * 16u + 7u);
    int32_t next = v->envelope.value;
    unsigned rate = 0u, mode = 0u, known = v->envelope.known && v->mode_known;
    unsigned level = 0u;
    if (v->mode == SM16_RELEASE) {
        next -= 8;
        if (next < 0) next = 0;
        v->envelope = sm16_scalar(next, known);
        return;
    }
    known &= sm16_known(d->adsr1, 128u);
    if (d->adsr1.value & 128u) {
        known &= sm16_known(second, 255u);
        level = second.value >> 5u;
        if (v->mode == SM16_ATTACK) {
            known &= sm16_known(d->adsr1, 15u);
            rate = (d->adsr1.value & 15u) * 2u + 1u;
            next += rate == 31u ? 1024 : 32;
        } else {
            next = next - 1 - sm16_asr(next - 1, 8u);
            rate = second.value & 31u;
            if (v->mode == SM16_DECAY) {
                known &= sm16_known(d->adsr1, 0x70u);
                rate = ((d->adsr1.value >> 4u) & 7u) * 2u + 16u;
            }
        }
    } else {
        known &= sm16_known(gain, 255u);
        mode = gain.value >> 5u; level = gain.value >> 5u;
        rate = gain.value & 31u;
        if (mode < 4u) {
            next = (int32_t)gain.value * 16; rate = 31u;
            /* DirectGAIN overwrites the old envelope; only selected mode and
             * current control/data, not old envelope knownness, are required. */
            known = v->mode_known && sm16_known(d->adsr1, 128u) && sm16_known(gain, 255u);
        }
        else if (mode == 4u) next -= 32;
        else if (mode == 5u) next = next - 1 - sm16_asr(next - 1, 8u);
        else {
            next += 32;
            if (mode == 7u) {
                known &= v->hidden_envelope.known;
                if (v->hidden_envelope.value >= 0x600) next -= 24;
            }
        }
    }
    if (v->mode == SM16_DECAY && sm16_asr(next, 8u) == (int32_t)level) v->mode = SM16_SUSTAIN;
    v->hidden_envelope = sm16_scalar(next, known);
    if (next < 0 || next > 2047) {
        if (v->mode == SM16_ATTACK) v->mode = SM16_DECAY;
        next = next < 0 ? 0 : 2047;
    }
    v->mode_known &= (uint8_t)known;
    if (sm16_rate(d, rate)) v->envelope = sm16_scalar(next, known);
    else if (!known) v->envelope.known = 0u;
}

static Sm16Scalar sm16_interpolate(const Sm16Voice *v) {
    unsigned fraction = (v->interpolation >> 4u) & 255u;
    unsigned base = v->decode_position + (v->interpolation >> 12u);
    unsigned weights[4] = {255u - fraction, 511u - fraction, 256u + fraction, fraction};
    unsigned i, known = v->interpolation_known;
    int32_t sum = 0;
    for (i = 0u; i < 4u; ++i) {
        Sm16Scalar sample = v->decoded[(base + i) % 12u];
        unsigned weight = sm16_gaussian[weights[i]];
        if (weight != 0u && !sample.known) known = 0u;
        sum += sm16_asr(sample.value * (int32_t)weight, 11u);
        if (i == 2u) sum = sm16_wrap16(sum);
    }
    return sm16_scalar(sm16_even(sum), known);
}

static void sm16_decode(Sm16Dsp *d, Sm16Voice *v) {
    Sm08Value bytes[2];
    Sm16Scalar p1 = v->decoded[(v->decode_position + 11u) % 12u];
    Sm16Scalar p2 = v->decoded[(v->decode_position + 10u) % 12u];
    unsigned i, range = d->brr_header.value >> 4u, filter = (d->brr_header.value >> 2u) & 3u;
    bytes[0] = d->brr_data;
    bytes[1] = sm16_aram(d, sm16_add_address(v->brr_address, (unsigned)v->brr_offset + 1u));
    for (i = 0u; i < 4u; ++i) {
        unsigned shift = (i & 1u) != 0u ? 0u : 4u;
        unsigned nibble = (bytes[i / 2u].value >> shift) & 15u;
        unsigned known = v->brr_address.known && sm16_known(d->brr_header, 0xfcu) &&
                         sm16_known(bytes[i / 2u], 15u << shift);
        int32_t value = nibble >= 8u ? (int32_t)nibble - 16 : (int32_t)nibble;
        int32_t older = sm16_asr(p2.value, 1u);
        if (range <= 12u) value = sm16_asr(value * (int32_t)(1u << range), 1u);
        else value = value < 0 ? -2048 : 0;
        if (filter == 1u) {
            value += sm16_asr(p1.value, 1u) + sm16_asr(-p1.value, 5u);
            known &= p1.known;
        } else if (filter == 2u) {
            value += p1.value - older + sm16_asr(older, 4u) + sm16_asr(-3 * p1.value, 6u);
            known &= p1.known && p2.known;
        } else if (filter == 3u) {
            value += p1.value - older + sm16_asr(-13 * p1.value, 7u) + sm16_asr(3 * older, 4u);
            known &= p1.known && p2.known;
        }
        value = sm16_wrap16(sm16_clamp(value) * 2);
        p2 = p1; p1 = sm16_scalar(value, known);
        v->decoded[v->decode_position] = p1;
        v->decode_position = (uint8_t)((v->decode_position + 1u) % 12u);
    }
}

static void sm16_mix(Sm16Dsp *d, unsigned voice, unsigned channel) {
    Sm16Scalar sample = sm16_scale(d->voice_output, sm16_reg(d, voice * 16u + channel), 7u);
    unsigned mask = 1u << voice;
    d->dry[channel] = sm16_sum(d->dry[channel], sample);
    if (d->echo_enable.value & mask) {
        if (!sm16_known(d->echo_enable, mask) && !(sample.known && sample.value == 0)) sample.known = 0u;
        d->echo_input[channel] = sm16_sum(d->echo_input[channel], sample);
    } else if (!sm16_known(d->echo_enable, mask) && !(sample.known && sample.value == 0)) {
        d->echo_input[channel].known = 0u;
    }
}

static void sm16_voice1(Sm16Dsp *d, unsigned index) {
    d->directory_address.value = (uint16_t)((unsigned)d->directory.value * 256u + (unsigned)d->source.value * 4u);
    d->directory_address.known = (uint8_t)(sm16_known(d->directory, 255u) && sm16_known(d->source, 255u));
    d->source = sm16_reg(d, index * 16u + 4u);
}

static void sm16_voice2(Sm16Dsp *d, unsigned index) {
    Sm16Voice *v = &d->voice[index];
    Sm16Address address = d->directory_address;
    Sm08Value low, high, pitch = sm16_reg(d, index * 16u + 2u);
    if (!v->key_delay) address = sm16_add_address(address, 2u);
    address.known &= v->key_delay_known;
    low = sm16_aram(d, address); high = sm16_aram(d, sm16_add_address(address, 1u));
    d->next_brr.value = (uint16_t)(low.value | ((uint16_t)high.value << 8u));
    d->next_brr.known = (uint8_t)(sm16_known(low, 255u) && sm16_known(high, 255u));
    d->adsr1 = sm16_reg(d, index * 16u + 5u);
    d->pitch = pitch.value; d->pitch_known = (uint8_t)sm16_known(pitch, 255u);
}

static void sm16_voice3a(Sm16Dsp *d, unsigned index) {
    Sm08Value value = sm16_reg(d, index * 16u + 3u);
    d->pitch |= (uint16_t)((value.value & 63u) << 8u);
    d->pitch_known &= (uint8_t)sm16_known(value, 63u);
}

static void sm16_voice3b(Sm16Dsp *d, unsigned index) {
    Sm16Voice *v = &d->voice[index];
    d->brr_header = sm16_aram(d, v->brr_address);
    d->brr_data = sm16_aram(d, sm16_add_address(v->brr_address, v->brr_offset));
}

static void sm16_voice3c(Sm16Dsp *d, unsigned index) {
    Sm16Voice *v = &d->voice[index];
    Sm16Scalar sample;
    unsigned bit = 1u << index;
    unsigned reset = sm16_known(d->flags, 0x80u) && (d->flags.value & 0x80u);
    unsigned ended = sm16_known(d->brr_header, 3u) && (d->brr_header.value & 3u) == 1u;
    if (index != 0u && !(d->pitch_known && d->pitch == 0u)) {
        if (d->pmon.value & bit) {
            int32_t pitch = (int32_t)d->pitch + sm16_asr(sm16_asr(d->voice_output.value, 5u) * d->pitch, 10u);
            d->pitch = (uint16_t)pitch;
            d->pitch_known &= (uint8_t)(d->voice_output.known && sm16_known(d->pmon, bit));
        } else if (!sm16_known(d->pmon, bit)) d->pitch_known = 0u;
    }
    if (v->key_delay != 0u) {
        if (v->key_delay == 5u) {
            v->brr_address = d->next_brr; v->brr_offset = 1u; v->decode_position = 0u;
            v->brr_address.known &= v->key_delay_known;
            d->brr_header = (Sm08Value){0u, v->key_delay_known ? 255u : 0u};
        }
        v->envelope = sm16_scalar(0, v->key_delay_known);
        v->hidden_envelope = v->envelope;
        v->interpolation = 0u; v->interpolation_known = v->key_delay_known;
        --v->key_delay;
        if ((v->key_delay & 3u) != 0u) v->interpolation = 0x4000u;
        d->pitch = 0u; d->pitch_known = v->key_delay_known;
    }
    sample = sm16_interpolate(v);
    if (d->noise_enable.value & bit) sample = sm16_scalar(sm16_wrap16((int32_t)d->noise_lfsr * 2), d->noise_known);
    if (!sm16_known(d->noise_enable, bit)) sample.known = 0u;
    d->voice_output = sm16_scalar(sm16_even(sm16_asr(sample.value * v->envelope.value, 11u)),
        (sample.known && v->envelope.known) || (v->envelope.known && v->envelope.value == 0));
    v->output = d->voice_output;
    v->envx = (Sm08Value){(uint8_t)((unsigned)v->envelope.value >> 4u), v->envelope.known ? 255u : 0u};
    if (reset || ended) {
        v->mode = SM16_RELEASE; v->mode_known = 1u; v->envelope = sm16_scalar(0, 1u);
    } else if (!sm16_known(d->flags, 0x80u) || !sm16_known(d->brr_header, 3u)) {
        v->mode_known = 0u;
        if (v->envelope.value != 0 || !v->envelope.known) v->envelope.known = 0u;
    }
    if (d->alternating_sample) {
        if (sm16_known(d->koff_latch, bit)) {
            if (d->koff_latch.value & bit) { v->mode = SM16_RELEASE; v->mode_known = 1u; }
        } else v->mode_known = 0u;
        if (sm16_known(d->kon_latch, bit)) {
            if (d->kon_latch.value & bit) {
                v->key_delay = 5u; v->key_delay_known = 1u;
                v->mode = SM16_ATTACK; v->mode_known = 1u;
            }
        } else { v->key_delay_known = 0u; v->mode_known = 0u; }
    }
    if (v->key_delay == 0u && v->key_delay_known) sm16_envelope(d, index);
    else if (!v->key_delay_known) v->envelope.known = 0u;
    if (reset) {
        /* Reset's envelope annihilator is not a fabricated BRR/address tag. */
        v->envelope = sm16_scalar(0, 1u);
    }
}

static void sm16_voice3(Sm16Dsp *d, unsigned index) {
    sm16_voice3a(d, index); sm16_voice3b(d, index); sm16_voice3c(d, index);
}

static void sm16_voice4(Sm16Dsp *d, unsigned index) {
    Sm16Voice *v = &d->voice[index];
    unsigned i, cursor_known = v->brr_address.known && v->interpolation_known;
    v->looped = (Sm08Value){0u, 1u};
    if (!v->interpolation_known) {
        /* Decode/no-decode also selects offset, decoder position, histories
         * and possibly the next block. Keep representative values, but the
         * physical cursor and every history slot must join both alternatives.
         * A known key-start in voice3c establishes a fresh cursor later. */
        v->looped.known_mask = 0u;
        v->brr_address.known = 0u;
        for (i = 0u; i < 12u; ++i) v->decoded[i].known = 0u;
    }
    if (v->interpolation >= 0x4000u) {
        sm16_decode(d, v);
        v->brr_offset = (uint8_t)(v->brr_offset + 2u);
        if (v->brr_offset >= 9u) {
            v->brr_address = sm16_add_address(v->brr_address, 9u);
            if (d->brr_header.value & 1u) {
                v->brr_address = d->next_brr; v->looped.value = 1u;
            }
            /* A representative loop reload cannot recover an uncertain
             * offset/decoder path even if next_brr itself is known. */
            v->brr_address.known &= (uint8_t)(cursor_known && sm16_known(d->brr_header, 1u));
            v->looped.known_mask &= (uint8_t)sm16_known(d->brr_header, 1u);
            v->brr_offset = 1u;
        }
    }
    v->interpolation = (uint16_t)((v->interpolation & 0x3fffu) + d->pitch);
    if (v->interpolation > 0x7fffu) v->interpolation = 0x7fffu;
    v->interpolation_known &= d->pitch_known;
    sm16_mix(d, index, 0u);
}

static void sm16_voice5(Sm16Dsp *d, unsigned index) {
    Sm16Voice *v = &d->voice[index];
    Sm08Value end = sm16_reg(d, 0x7cu);
    unsigned bit = 1u << index;
    unsigned a = (end.value & bit) != 0u, b = (v->looped.value & 1u) != 0u;
    unsigned known = (sm16_known(end, bit) && a) || (sm16_known(v->looped, 1u) && b) ||
                     (sm16_known(end, bit) && sm16_known(v->looped, 1u));
    sm16_mix(d, index, 1u);
    d->endx_latch = end;
    d->endx_latch.value = (uint8_t)((end.value & (uint8_t)~bit) | ((a || b) ? bit : 0u));
    d->endx_latch.known_mask = (uint8_t)((end.known_mask & (uint8_t)~bit) | (known ? bit : 0u));
    if (v->key_delay_known && v->key_delay == 5u) {
        d->endx_latch.value &= (uint8_t)~bit; d->endx_latch.known_mask |= (uint8_t)bit;
    } else if (!v->key_delay_known) d->endx_latch.known_mask &= (uint8_t)~bit;
}

static void sm16_voice6(Sm16Dsp *d) {
    d->outx_latch = (Sm08Value){(uint8_t)sm16_asr(d->voice_output.value, 8u), d->voice_output.known ? 255u : 0u};
}

static void sm16_voice7(Sm16Dsp *d, unsigned index) {
    d->registers[0x7cu] = d->endx_latch;
    d->envx_latch = d->voice[index].envx;
}

static void sm16_voice8(Sm16Dsp *d, unsigned index) { d->registers[index * 16u + 9u] = d->outx_latch; }
static void sm16_voice9(Sm16Dsp *d, unsigned index) { d->registers[index * 16u + 8u] = d->envx_latch; }

static Sm16Scalar sm16_fir(Sm16Dsp *d, unsigned tap, unsigned channel) {
    return sm16_scale(d->echo_history[(d->history_index + tap + 1u) & 7u][channel],
                      sm16_reg(d, tap * 16u + 15u), 6u);
}

static void sm16_echo_read(Sm16Dsp *d, unsigned channel) {
    Sm16Address address = sm16_add_address(d->echo_pointer, channel * 2u);
    Sm08Value lo = sm16_aram(d, address), hi = sm16_aram(d, sm16_add_address(address, 1u));
    int32_t value = sm16_wrap16((int32_t)lo.value + (int32_t)hi.value * 256);
    d->echo_history[d->history_index][channel] = sm16_scalar(sm16_asr(value, 1u),
        sm16_known(lo, 255u) && sm16_known(hi, 255u));
}

static void sm16_echo22(Sm16Dsp *d) {
    unsigned channel;
    d->history_index = (uint8_t)((d->history_index + 1u) & 7u);
    d->echo_pointer.value = (uint16_t)((unsigned)d->echo_page.value * 256u + d->echo_offset);
    d->echo_pointer.known = (uint8_t)(sm16_known(d->echo_page, 255u) && d->echo_offset_known);
    sm16_echo_read(d, 0u);
    for (channel = 0u; channel < 2u; ++channel) d->fir[channel] = sm16_fir(d, 0u, channel);
}

static void sm16_echo_taps(Sm16Dsp *d, unsigned first, unsigned last) {
    unsigned tap, channel;
    for (tap = first; tap <= last; ++tap) {
        for (channel = 0u; channel < 2u; ++channel) {
            Sm16Scalar product = sm16_fir(d, tap, channel);
            d->fir[channel].value += product.value;
            d->fir[channel].known &= product.known;
        }
    }
}

static void sm16_echo23(Sm16Dsp *d) { sm16_echo_taps(d, 1u, 2u); sm16_echo_read(d, 1u); }

static void sm16_echo25(Sm16Dsp *d) {
    unsigned channel;
    sm16_echo_taps(d, 6u, 6u);
    for (channel = 0u; channel < 2u; ++channel) {
        Sm16Scalar last = sm16_fir(d, 7u, channel);
        d->fir[channel].value = sm16_even(sm16_wrap16(d->fir[channel].value) + sm16_wrap16(last.value));
        d->fir[channel].known &= last.known;
    }
}

static Sm16Scalar sm16_final_mix(Sm16Dsp *d, unsigned channel) {
    Sm16Scalar dry = sm16_scale(d->dry[channel], sm16_reg(d, channel * 16u + 0x0cu), 7u);
    Sm16Scalar wet = sm16_scale(d->fir[channel], sm16_reg(d, channel * 16u + 0x2cu), 7u);
    dry.value = sm16_wrap16(dry.value); wet.value = sm16_wrap16(wet.value);
    return sm16_sum(dry, wet);
}

static void sm16_echo26(Sm16Dsp *d) {
    unsigned channel;
    d->dry[0] = sm16_final_mix(d, 0u);
    for (channel = 0u; channel < 2u; ++channel) {
        Sm16Scalar feedback = sm16_scale(d->fir[channel], sm16_reg(d, 0x0du), 7u);
        feedback.value = sm16_wrap16(feedback.value);
        d->echo_input[channel] = sm16_sum(d->echo_input[channel], feedback);
        d->echo_input[channel].value = sm16_even(d->echo_input[channel].value);
    }
}

static Sm08Status sm16_pcm_push(Sm16Dsp *d, Sm16Scalar left, Sm16Scalar right) {
    unsigned channel, byte, known = left.known && right.known;
    uint16_t sample[2] = {(uint16_t)left.value, (uint16_t)right.value};
    if (d->pcm_count >= SM16_PCM_CAPACITY) {
        ++d->overflows;
        return sm16_fault(d, SM08_STORAGE, 0x534450u, (Sm08Value){0u, 0u});
    }
    d->pcm[d->pcm_write * 2u] = (int16_t)left.value;
    d->pcm[d->pcm_write * 2u + 1u] = (int16_t)right.value;
    d->pcm_known[d->pcm_write] = (uint8_t)known;
    d->pcm_write = (d->pcm_write + 1u) % SM16_PCM_CAPACITY;
    ++d->pcm_count; ++d->frames;
    if (known) ++d->known_frames; else ++d->unknown_frames;
    for (channel = 0u; channel < 2u; ++channel) {
        for (byte = 0u; byte < 2u; ++byte) {
            d->pcm_hash ^= (uint8_t)(sample[channel] >> (byte * 8u));
            d->pcm_hash *= UINT64_C(1099511628211);
        }
    }
    return SM08_OK;
}

static Sm08Status sm16_echo27(Sm16Dsp *d) {
    Sm16Scalar left = d->dry[0], right = sm16_final_mix(d, 1u);
    if (sm16_known(d->flags, 0x40u) && (d->flags.value & 0x40u)) {
        left = sm16_scalar(0, 1u); right = left;
    } else if (!sm16_known(d->flags, 0x40u)) { left.known = 0u; right.known = 0u; }
    d->dry[0] = sm16_scalar(0, 1u); d->dry[1] = d->dry[0];
    return sm16_pcm_push(d, left, right);
}

Sm08Status sm16_sdsp_aram_write_word(Sm16Dsp *d, Sm16Address address, Sm16Scalar sample) {
    uint16_t next = (uint16_t)(address.value + 1u);
    uint16_t bits = (uint16_t)sm16_even(sample.value);
    if (!sm16_attached(d)) return SM08_ARGUMENT;
    if (d->bus->fault.status != SM08_OK) return d->bus->fault.status;
    if (!address.known) return sm16_fault(d, SM08_UNKNOWN, address.value, (Sm08Value){0u, 0u});
    /* Separate DSP writer: no permission is borrowed from an active SPC PC.
     * Both bytes are checked before either physical byte is changed. */
    if (sm13_aot_protected(address.value))
        return sm16_fault(d, SM08_GUARD, address.value, (Sm08Value){(uint8_t)bits, sample.known ? 255u : 0u});
    if (sm13_aot_protected(next))
        return sm16_fault(d, SM08_GUARD, next, (Sm08Value){(uint8_t)(bits >> 8u), sample.known ? 255u : 0u});
    d->apu->aram[address.value] = (Sm08Value){(uint8_t)bits, sample.known ? 255u : 0u};
    d->apu->aram[next] = (Sm08Value){(uint8_t)(bits >> 8u), sample.known ? 255u : 0u};
    d->aram_writes += 2u;
    return SM08_OK;
}

static Sm08Status sm16_echo_write(Sm16Dsp *d, unsigned channel) {
    Sm08Status status;
    if (!sm16_known(d->echo_write_disable, 0x20u))
        return sm16_fault(d, SM08_UNKNOWN, 0xf36cu, d->echo_write_disable);
    if ((d->echo_write_disable.value & 0x20u) == 0u) {
        status = sm16_sdsp_aram_write_word(d, sm16_add_address(d->echo_pointer, channel * 2u), d->echo_input[channel]);
        if (status != SM08_OK) return status;
    }
    d->echo_input[channel] = sm16_scalar(0, 1u);
    return SM08_OK;
}

static Sm08Status sm16_echo29(Sm16Dsp *d) {
    Sm08Value delay = sm16_reg(d, 0x7du);
    Sm08Status status;
    if (d->echo_offset_known && d->echo_offset == 0u) {
        d->echo_length = (uint16_t)((delay.value & 15u) << 11u);
        d->echo_length_known = (uint8_t)sm16_known(delay, 15u);
    }
    d->echo_offset = (uint16_t)(d->echo_offset + 4u);
    if (d->echo_length == 0u || d->echo_offset >= d->echo_length) d->echo_offset = 0u;
    if (d->echo_length_known && d->echo_length == 0u) {
        d->echo_offset = 0u; d->echo_offset_known = 1u;
    } else if (!d->echo_length_known) d->echo_offset_known = 0u;
    /* A valid echo controller has at most15*2048 bytes. Stable EDL0 for
     * one maximal traversal plus the next length latch erases any retained
     * cursor/length uncertainty, without manufacturing a cold cursor. */
    if (sm16_known(delay, 15u) && (delay.value & 15u) == 0u) {
        if (d->zero_delay_samples < 7681u) ++d->zero_delay_samples;
        if (d->zero_delay_samples == 7681u) {
            d->echo_offset = 0u; d->echo_length = 0u;
            d->echo_offset_known = 1u; d->echo_length_known = 1u;
        }
    } else d->zero_delay_samples = 0u;
    status = sm16_echo_write(d, 0u);
    if (status != SM08_OK) return status;
    d->echo_page = sm16_reg(d, 0x6du);
    d->echo_write_disable = d->flags;
    return SM08_OK;
}

Sm08Status sm16_sdsp_power_on(Sm16Dsp *d, Sm12Apu *apu) {
    unsigned i;
    if (d == NULL || apu == NULL || apu->bus == NULL || apu->scheduler == NULL ||
        apu->scheduler->bus != apu->bus || apu->smp_cycles != 0u || apu->bound) return SM08_ARGUMENT;
    if (apu->bus->fault.status != SM08_OK) return apu->bus->fault.status;
    memset(d, 0, sizeof(*d));
    d->apu = apu; d->bus = apu->bus;
    d->flags = (Sm08Value){0xe0u, 255u};
    d->echo_write_disable = d->flags;
    d->noise_lfsr = 0x4000u; d->noise_known = 1u;
    d->alternating_sample = 1u;
    d->pcm_hash = UINT64_C(14695981039346656037);
    d->dry[0] = sm16_scalar(0, 1u); d->dry[1] = d->dry[0];
    d->echo_input[0] = d->dry[0]; d->echo_input[1] = d->dry[0];
    d->endx_latch = (Sm08Value){0u, 255u};
    d->outx_latch = d->endx_latch; d->envx_latch = d->endx_latch;
    d->registers[0x7cu] = d->endx_latch;
    for (i = 0u; i < SM16_VOICES; ++i) {
        Sm16Voice *v = &d->voice[i];
        v->envelope = sm16_scalar(0, 1u); v->hidden_envelope = sm16_scalar(0, 0u);
        v->output = v->envelope; v->mode = SM16_RELEASE; v->mode_known = 1u;
        v->brr_offset = 1u;
        v->envx = (Sm08Value){0u, 255u};
        d->registers[i * 16u + 8u] = v->envx;
        d->registers[i * 16u + 9u] = v->envx;
    }
    /* Raw FLG readback, all unforced controls, BRR/echo RAM and histories,
     * addresses, retained cursor/length remain unknown despite representatives. */
    return SM08_OK;
}

Sm08Status sm16_sdsp_read(Sm16Dsp *d, uint8_t address, Sm08Value *out) {
    if (!sm16_attached(d) || out == NULL) return SM08_ARGUMENT;
    if (d->bus->fault.status != SM08_OK) return d->bus->fault.status;
    *out = d->registers[address & 127u];
    ++d->register_reads;
    return SM08_OK;
}

Sm08Status sm16_sdsp_write(Sm16Dsp *d, uint8_t address, Sm08Value value) {
    Sm08Value previous;
    if (!sm16_attached(d)) return SM08_ARGUMENT;
    if (d->bus->fault.status != SM08_OK) return d->bus->fault.status;
    /* The12address latch suppresses mirrored writes; keep standalone API same. */
    if (address >= 128u) return SM08_OK;
    previous = d->registers[address];
    d->registers[address] = value;
    ++d->register_writes;
    if ((address & 15u) == 8u) d->envx_latch = value;
    if ((address & 15u) == 9u) d->outx_latch = value;
    if (address == 0x4cu) d->kon_pending = value;
    if (address == 0x6cu) d->flags = value;
    if (address == 0x7cu) {
        d->endx_latch = (Sm08Value){0u, 255u};
        d->registers[0x7cu] = d->endx_latch;
    }
    if (address == 0x7du &&
        (((previous.known_mask ^ value.known_mask) & 15u) != 0u ||
         ((previous.value ^ value.value) & previous.known_mask & value.known_mask & 15u) != 0u))
        d->zero_delay_samples = 0u;
    return SM08_OK;
}

Sm08Status sm16_sdsp_step(Sm16Dsp *d, uint64_t smp_cycle, uint8_t phase) {
    Sm08Status status = SM08_OK;
    if (!sm16_attached(d)) return SM08_ARGUMENT;
    if (d->bus->fault.status != SM08_OK) return d->bus->fault.status;
    if (phase >= SM16_PHASES || phase != d->phase || d->last_smp_cycle == UINT64_MAX ||
        smp_cycle != d->last_smp_cycle + 1u)
        return sm16_fault(d, SM08_GUARD, phase, (Sm08Value){phase, 255u});
    switch (phase) {
        case 0u: sm16_voice5(d, 0u); sm16_voice2(d, 1u); break;
        case 1u: sm16_voice6(d); sm16_voice3(d, 1u); break;
        case 2u: sm16_voice7(d, 0u); sm16_voice4(d, 1u); sm16_voice1(d, 3u); break;
        case 3u: sm16_voice8(d, 0u); sm16_voice5(d, 1u); sm16_voice2(d, 2u); break;
        case 4u: sm16_voice9(d, 0u); sm16_voice6(d); sm16_voice3(d, 2u); break;
        case 5u: sm16_voice7(d, 1u); sm16_voice4(d, 2u); sm16_voice1(d, 4u); break;
        case 6u: sm16_voice8(d, 1u); sm16_voice5(d, 2u); sm16_voice2(d, 3u); break;
        case 7u: sm16_voice9(d, 1u); sm16_voice6(d); sm16_voice3(d, 3u); break;
        case 8u: sm16_voice7(d, 2u); sm16_voice4(d, 3u); sm16_voice1(d, 5u); break;
        case 9u: sm16_voice8(d, 2u); sm16_voice5(d, 3u); sm16_voice2(d, 4u); break;
        case 10u: sm16_voice9(d, 2u); sm16_voice6(d); sm16_voice3(d, 4u); break;
        case 11u: sm16_voice7(d, 3u); sm16_voice4(d, 4u); sm16_voice1(d, 6u); break;
        case 12u: sm16_voice8(d, 3u); sm16_voice5(d, 4u); sm16_voice2(d, 5u); break;
        case 13u: sm16_voice9(d, 3u); sm16_voice6(d); sm16_voice3(d, 5u); break;
        case 14u: sm16_voice7(d, 4u); sm16_voice4(d, 5u); sm16_voice1(d, 7u); break;
        case 15u: sm16_voice8(d, 4u); sm16_voice5(d, 5u); sm16_voice2(d, 6u); break;
        case 16u: sm16_voice9(d, 4u); sm16_voice6(d); sm16_voice3(d, 6u); break;
        case 17u: sm16_voice1(d, 0u); sm16_voice7(d, 5u); sm16_voice4(d, 6u); break;
        case 18u: sm16_voice8(d, 5u); sm16_voice5(d, 6u); sm16_voice2(d, 7u); break;
        case 19u: sm16_voice9(d, 5u); sm16_voice6(d); sm16_voice3(d, 7u); break;
        case 20u: sm16_voice1(d, 1u); sm16_voice7(d, 6u); sm16_voice4(d, 7u); break;
        case 21u: sm16_voice8(d, 6u); sm16_voice5(d, 7u); sm16_voice2(d, 0u); break;
        case 22u: sm16_voice3a(d, 0u); sm16_voice9(d, 6u); sm16_voice6(d); sm16_echo22(d); break;
        case 23u: sm16_voice7(d, 7u); sm16_echo23(d); break;
        case 24u: sm16_voice8(d, 7u); sm16_echo_taps(d, 3u, 5u); break;
        case 25u: sm16_voice3b(d, 0u); sm16_voice9(d, 7u); sm16_echo25(d); break;
        case 26u: sm16_echo26(d); break;
        case 27u: d->pmon = sm16_reg(d, 0x2du); d->pmon.value &= 0xfeu; d->pmon.known_mask |= 1u;
                  status = sm16_echo27(d); break;
        case 28u: d->directory = sm16_reg(d, 0x5du); d->noise_enable = sm16_reg(d, 0x3du);
                  d->echo_enable = sm16_reg(d, 0x4du); d->echo_write_disable = d->flags; break;
        case 29u: d->alternating_sample ^= 1u;
                  if (d->alternating_sample) {
                      Sm08Value pending = d->kon_pending;
                      unsigned ones = d->kon_latch.value & d->kon_latch.known_mask;
                      unsigned zeros = (unsigned)(uint8_t)~d->kon_latch.value & d->kon_latch.known_mask;
                      d->kon_pending.value &= (uint8_t)~d->kon_latch.value;
                      d->kon_pending.known_mask = (uint8_t)(ones |
                          (zeros & pending.known_mask & pending.value) |
                          ((unsigned)(uint8_t)~pending.value & pending.known_mask));
                  }
                  status = sm16_echo29(d); break;
        case 30u: if (d->alternating_sample) { d->kon_latch = d->kon_pending; d->koff_latch = sm16_reg(d, 0x5cu); }
                  d->rate_counter = d->rate_counter != 0u ? (uint16_t)(d->rate_counter - 1u) : 0x77ffu;
                  if (sm16_known(d->flags, 31u)) {
                      if (sm16_rate(d, d->flags.value & 31u))
                          d->noise_lfsr = (uint16_t)((d->noise_lfsr >> 1u) |
                              (((d->noise_lfsr << 14u) ^ (d->noise_lfsr << 13u)) & 0x4000u));
                  } else d->noise_known = 0u;
                  sm16_voice3c(d, 0u); status = sm16_echo_write(d, 1u); break;
        case 31u: sm16_voice4(d, 0u); sm16_voice1(d, 2u); break;
        default: return SM08_ARGUMENT;
    }
    if (status != SM08_OK) return status;
    d->phase = (uint8_t)((phase + 1u) & 31u);
    d->last_smp_cycle = smp_cycle; ++d->phase_steps;
    return SM08_OK;
}

static Sm08Status sm16_port_step(void *context, Sm08Bus *bus, uint64_t cycle, uint8_t phase) {
    Sm16Dsp *d = context;
    if (!sm16_attached(d) || bus != d->bus) return SM08_ARGUMENT;
    return sm16_sdsp_step(d, cycle, phase);
}
static Sm08Status sm16_port_read(void *context, uint8_t address, Sm08Value *out) {
    return sm16_sdsp_read(context, address, out);
}
static Sm08Status sm16_port_write(void *context, uint8_t address, Sm08Value value) {
    return sm16_sdsp_write(context, address, value);
}
Sm12DspPort sm16_sdsp_port(Sm16Dsp *d) {
    Sm12DspPort port = {d, sm16_port_step, sm16_port_read, sm16_port_write};
    return port;
}
Sm08Status sm16_sdsp_bind(Sm16Dsp *d) {
    Sm08Status status;
    if (!sm16_attached(d) || d->bound || d->apu->dsp.step != NULL ||
        d->apu->dsp.read != NULL || d->apu->dsp.write != NULL) return SM08_ARGUMENT;
    if (d->bus->fault.status != SM08_OK) return d->bus->fault.status;
    status = sm12_apu_bind_dsp(d->apu, sm16_sdsp_port(d));
    if (status != SM08_OK) return status;
    d->bound = 1u;
    return SM08_OK;
}
uint32_t sm16_sdsp_pcm_available(const Sm16Dsp *d) { return sm16_attached(d) ? d->pcm_count : 0u; }
int sm16_sdsp_pcm_metrics(const Sm16Dsp *d, Sm16PcmMetrics *out) {
    if (!sm16_attached(d) || out == NULL) return 0;
    out->native_rate = SM16_NATIVE_HZ; out->channels = 2u;
    out->format = SM16_PCM_SIGNED16_STEREO; out->frames_available = d->pcm_count;
    out->frames = d->frames; out->known_frames = d->known_frames;
    out->unknown_frames = d->unknown_frames; out->overflows = d->overflows;
    out->phase_steps = d->phase_steps; out->smp_cycles = d->last_smp_cycle;
    out->pcm_hash = d->pcm_hash; out->next_phase = d->phase;
    return 1;
}
uint32_t sm16_sdsp_pcm_drain(Sm16Dsp *d, int16_t *stereo, uint8_t *known, uint32_t capacity) {
    uint32_t count = 0u;
    if (!sm16_attached(d) || stereo == NULL || known == NULL) return 0u;
    while (count < capacity && d->pcm_count != 0u) {
        stereo[count * 2u] = d->pcm[d->pcm_read * 2u];
        stereo[count * 2u + 1u] = d->pcm[d->pcm_read * 2u + 1u];
        known[count] = d->pcm_known[d->pcm_read];
        d->pcm_read = (d->pcm_read + 1u) % SM16_PCM_CAPACITY;
        --d->pcm_count; ++count;
    }
    return count;
}
