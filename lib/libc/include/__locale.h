#ifndef __LIBC_LOCALE_H
#define __LIBC_LOCALE_H

#include <locale.h>
#include <stdint.h>

typedef __SIZE_TYPE__ size_t;

struct __locale_t {
	struct __locale_map {
		const void *map;
		size_t map_size;
		char name[24];
	} maps[6];
};

typedef struct __locale_t *locale_t;

static const struct __locale_t __c_locale = { 0 };

static const struct __locale_t __utf8_locale = {
	.maps[LC_CTYPE] = { .map = &((const uint32_t[]){ 0x950412de, 0, -1, -1,
							 -1 }),
			    .map_size = sizeof(uint32_t) * 5,
			    .name = "C.UTF-8" },
};

#undef MB_CUR_MAX
#define MB_CUR_MAX (((locale_t) & __utf8_locale) ? 4 : 1)

static inline int __mb_cur_max(void)
{
	return MB_CUR_MAX;
}

static inline int __locale_allocated(locale_t loc)
{
	return loc != (locale_t)&__c_locale && loc != (locale_t)&__utf8_locale;
}

#endif
