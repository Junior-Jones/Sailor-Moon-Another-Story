#ifndef SAILOR_MOON_SPC700_RETIRED_INIT_H
#define SAILOR_MOON_SPC700_RETIRED_INIT_H
#include "sailor_moon_spc700.h"
/* Private named source-lifetime guard. The public/old13 ABI and state layout
 * are unchanged. Both the semantic writer and APU callback use this predicate. */
int sm13_retired_init_write_allowed(const Sm13State *, uint16_t, Sm08Value);
#endif
