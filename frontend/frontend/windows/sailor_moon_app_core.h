#ifndef SAILOR_MOON_APP_CORE_H
#define SAILOR_MOON_APP_CORE_H

#include "sailor_moon_static_recomp.h"

#ifdef __cplusplus
extern "C" {
#endif

int sailor_moon_recomp_write_diagnostic_log(
    const SailorMoonRecomp *instance, const char *path,
    const char *screenshot_path, char *error, size_t error_capacity);
int sailor_moon_recomp_append_diagnostic_log(
    const SailorMoonRecomp *instance, const char *path,
    const char *section_title, char *error, size_t error_capacity);

#ifdef __cplusplus
}
#endif
#endif
