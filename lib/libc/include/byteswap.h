#ifndef __LIBC_BYTESWAP_H
#define __LIBC_BYTESWAP_H

#define bswap16(x) __builtin_bswap16(x)
#define bswap32(x) __builtin_bswap32(x)
#define bswap64(x) __builtin_bswap64(x)

#endif
