#include <endian.h> // for be16toh
#include <stdint.h> // for uint16_t

uint16_t be16toh(uint16_t big_endian_16bits)
{
#if __BYTE_ORDER == __LITTLE_ENDIAN
	return __builtin_bswap16(big_endian_16bits);
#else
	return big_endian_16bits;
#endif
}
