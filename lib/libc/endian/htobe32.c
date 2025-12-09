#include <endian.h> // for htobe32
#include <stdint.h> // for uint32_t

uint32_t htobe32(uint32_t host_32bits)
{
#if __BYTE_ORDER == __LITTLE_ENDIAN
	return __builtin_bswap32(host_32bits);
#else
	return host_32bits;
#endif
}
