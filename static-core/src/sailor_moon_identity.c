#include "sailor_moon_identity.h"
#include "sailor_moon_bus_types.h"
#include <string.h>

/* Own01 verified English2.08 image. The caller supplies bytes, not a digest. */
const uint8_t sm08_rom_sha256[32] = {
    0x96,0x90,0x86,0x3e,0xea,0x45,0x16,0x7e,0x69,0xb5,0x22,0xc1,0x24,0xb5,0x17,0xbd,
    0xc3,0x45,0x7e,0x70,0xdc,0x08,0x0d,0xdb,0xf9,0x25,0x46,0x2a,0x98,0x9a,0xce,0xc9
};
/* FIPS180-4 section4.2.2 cube-root constants. */
static const uint32_t sm08_k[64] = {
    0x428a2f98u,0x71374491u,0xb5c0fbcfu,0xe9b5dba5u,0x3956c25bu,0x59f111f1u,0x923f82a4u,0xab1c5ed5u,
    0xd807aa98u,0x12835b01u,0x243185beu,0x550c7dc3u,0x72be5d74u,0x80deb1feu,0x9bdc06a7u,0xc19bf174u,
    0xe49b69c1u,0xefbe4786u,0x0fc19dc6u,0x240ca1ccu,0x2de92c6fu,0x4a7484aau,0x5cb0a9dcu,0x76f988dau,
    0x983e5152u,0xa831c66du,0xb00327c8u,0xbf597fc7u,0xc6e00bf3u,0xd5a79147u,0x06ca6351u,0x14292967u,
    0x27b70a85u,0x2e1b2138u,0x4d2c6dfcu,0x53380d13u,0x650a7354u,0x766a0abbu,0x81c2c92eu,0x92722c85u,
    0xa2bfe8a1u,0xa81a664bu,0xc24b8b70u,0xc76c51a3u,0xd192e819u,0xd6990624u,0xf40e3585u,0x106aa070u,
    0x19a4c116u,0x1e376c08u,0x2748774cu,0x34b0bcb5u,0x391c0cb3u,0x4ed8aa4au,0x5b9cca4fu,0x682e6ff3u,
    0x748f82eeu,0x78a5636fu,0x84c87814u,0x8cc70208u,0x90befffau,0xa4506cebu,0xbef9a3f7u,0xc67178f2u
};
static uint32_t sm08_rotate(uint32_t value, uint32_t shift) {
    return (value >> shift) | (value << (32u - shift));
}
static void sm08_compress(uint32_t state[8], const uint8_t block[64]) {
    uint32_t w[64];
    uint32_t a,b,c,d,e,f,g,h;
    uint32_t i;
    for (i = 0u; i < 16u; i++) {
        w[i] = ((uint32_t)block[i*4u] << 24u) | ((uint32_t)block[i*4u+1u] << 16u) |
               ((uint32_t)block[i*4u+2u] << 8u) | block[i*4u+3u];
    }
    for (i = 16u; i < 64u; i++) {
        uint32_t s0 = sm08_rotate(w[i-15u],7u) ^ sm08_rotate(w[i-15u],18u) ^ (w[i-15u] >> 3u);
        uint32_t s1 = sm08_rotate(w[i-2u],17u) ^ sm08_rotate(w[i-2u],19u) ^ (w[i-2u] >> 10u);
        w[i] = w[i-16u] + s0 + w[i-7u] + s1;
    }
    a=state[0]; b=state[1]; c=state[2]; d=state[3];
    e=state[4]; f=state[5]; g=state[6]; h=state[7];
    for (i = 0u; i < 64u; i++) {
        uint32_t sigma1 = sm08_rotate(e,6u) ^ sm08_rotate(e,11u) ^ sm08_rotate(e,25u);
        uint32_t choose = (e & f) ^ ((~e) & g);
        uint32_t t1 = h + sigma1 + choose + sm08_k[i] + w[i];
        uint32_t sigma0 = sm08_rotate(a,2u) ^ sm08_rotate(a,13u) ^ sm08_rotate(a,22u);
        uint32_t majority = (a & b) ^ (a & c) ^ (b & c);
        uint32_t t2 = sigma0 + majority;
        h=g; g=f; f=e; e=d+t1; d=c; c=b; b=a; a=t1+t2;
    }
    state[0]=state[0]+a; state[1]=state[1]+b; state[2]=state[2]+c; state[3]=state[3]+d;
    state[4]=state[4]+e; state[5]=state[5]+f; state[6]=state[6]+g; state[7]=state[7]+h;
}
int sm08_sha256(const uint8_t *data, size_t size, uint8_t output[32]) {
    uint32_t state[8] = {0x6a09e667u,0xbb67ae85u,0x3c6ef372u,0xa54ff53au,0x510e527fu,0x9b05688cu,0x1f83d9abu,0x5be0cd19u};
    uint8_t tail[128] = {0};
    size_t cursor = 0u;
    size_t remainder, padded;
    uint64_t bits;
    uint32_t i;
    if (output == 0 || (data == 0 && size != 0u) || size > UINT64_MAX / 8u) return 0;
    while (size - cursor >= 64u) { sm08_compress(state, data + cursor); cursor = cursor + 64u; }
    remainder = size - cursor;
    if (remainder != 0u) memcpy(tail, data + cursor, remainder);
    tail[remainder] = 0x80u;
    padded = remainder < 56u ? 64u : 128u;
    bits = (uint64_t)size * 8u;
    for (i = 0u; i < 8u; i++) tail[padded-1u-i] = (uint8_t)(bits >> (i*8u));
    sm08_compress(state, tail);
    if (padded == 128u) sm08_compress(state, tail + 64u);
    for (i = 0u; i < 8u; i++) {
        output[i*4u] = (uint8_t)(state[i] >> 24u);
        output[i*4u+1u] = (uint8_t)(state[i] >> 16u);
        output[i*4u+2u] = (uint8_t)(state[i] >> 8u);
        output[i*4u+3u] = (uint8_t)state[i];
    }
    return 1;
}
int sm08_rom_matches(const uint8_t *data, size_t size) {
    uint8_t actual[32];
    if (data == 0 || size != SM08_ROM_SIZE) return 0;
    if (sm08_sha256(data,size,actual) == 0) return 0;
    return memcmp(actual,sm08_rom_sha256,32u) == 0;
}
