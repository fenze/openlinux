#ifndef __LIBC_BYTESWAP_H
#define __LIBC_BYTESWAP_H

#include <stdint.h>

static __inline uint16_t bswap_16(uint16_t x)
{
	return x << 8 | x >> 8;
}

static __inline uint32_t bswap_32(uint32_t x)
{
	return x >> 24 | x >> 8 & 0xff00 | x << 8 & 0xff0000 | x << 24;
}

static __inline uint64_t bswap_64(uint64_t x)
{
	return (bswap_32(x) + 0ULL) << 32 | bswap_32(x >> 32);
}

#endif
