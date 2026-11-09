#include "sailor_moon_sram.h"
#include "sailor_moon_identity.h"
#include <string.h>
static const uint8_t sm08_save_magic[8] = {0x53,0x4D,0x41,0x38,0x53,0x52,0x30,0x31};
static void sm08_le32(uint8_t *p, uint32_t value) {
    p[0]=(uint8_t)value; p[1]=(uint8_t)(value>>8u); p[2]=(uint8_t)(value>>16u); p[3]=(uint8_t)(value>>24u);
}
static uint32_t sm08_get32(const uint8_t *p) {
    return (uint32_t)p[0] | ((uint32_t)p[1]<<8u) | ((uint32_t)p[2]<<16u) | ((uint32_t)p[3]<<24u);
}
Sm08Status sm08_sram_encode(const Sm08Memory *m, uint8_t *output, size_t size, uint64_t *generation) {
    uint8_t digest[32];
    Sm08SramImage image;
    uint64_t token;
    Sm08Status status;
    if (m==0 || output==0 || generation==0 || size!=SM08_SRAM_FILE_SIZE) return SM08_ARGUMENT;
    status=sm08_memory_export_sram(m,&image,&token);
    if (status!=SM08_OK) return status;
    memset(output,0,SM08_SRAM_FILE_SIZE);
    memcpy(output,sm08_save_magic,8u);
    sm08_le32(output+8u,1u); sm08_le32(output+12u,SM08_SRAM_PAYLOAD_SIZE);
    memcpy(output+16u,sm08_rom_sha256,32u);
    memcpy(output+80u,image.values,sizeof(image.values));
    memcpy(output+80u+SM08_SRAM_SIZE,image.known,sizeof(image.known));
    /* Length/pointers are already valid for this bounded SHA call. */
    if (sm08_sha256(output,SM08_SRAM_FILE_SIZE,digest)==0) return SM08_BAD_SAVE;
    memcpy(output+48u,digest,32u);
    *generation=token;
    return SM08_OK;
}
Sm08Status sm08_sram_decode(Sm08Memory *m, const uint8_t *input, size_t size) {
    uint8_t candidate[SM08_SRAM_FILE_SIZE];
    uint8_t actual[32];
    Sm08SramImage image;
    if (m==0 || input==0) return SM08_ARGUMENT;
    if (m->rom==0 || m->rom_size!=SM08_ROM_SIZE) return SM08_BAD_ROM;
    if (m->access_started!=0u) return SM08_LATE_SRAM_LOAD;
    if (size!=SM08_SRAM_FILE_SIZE) return SM08_BAD_SAVE;
    if (memcmp(input,sm08_save_magic,8u)!=0 || sm08_get32(input+8u)!=1u ||
        sm08_get32(input+12u)!=SM08_SRAM_PAYLOAD_SIZE || memcmp(input+16u,sm08_rom_sha256,32u)!=0) return SM08_BAD_SAVE;
    memcpy(candidate,input,SM08_SRAM_FILE_SIZE);
    memset(candidate+48u,0,32u);
    if (sm08_sha256(candidate,SM08_SRAM_FILE_SIZE,actual)==0 || memcmp(actual,input+48u,32u)!=0) return SM08_BAD_SAVE;
    memcpy(image.values,input+80u,sizeof(image.values));
    memcpy(image.known,input+80u+SM08_SRAM_SIZE,sizeof(image.known));
    return sm08_memory_load_sram(m,&image);
}
