#ifndef SAILOR_MOON_IDENTITY_H
#define SAILOR_MOON_IDENTITY_H
#include <stddef.h>
#include <stdint.h>
extern const uint8_t sm08_rom_sha256[32];
int sm08_sha256(const uint8_t *data, size_t size, uint8_t output[32]);
int sm08_rom_matches(const uint8_t *data, size_t size);
#endif
