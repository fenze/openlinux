#include <endian.h> // for htole16
#include <stdint.h> // for uint16_t

uint16_t htole16(uint16_t host_16bits)
{
#if __BYTE_ORDER == __BIG_ENDIAN
	return __builtin_bswap16(host_16bits);
#else
	return host_16bits;
#endif
}
