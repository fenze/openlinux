#include <arpa/inet.h> // for uint32_t, htonl
#include <byteswap.h>  // for bswap32
#include <stdint.h>

uint32_t htonl(uint32_t hostlong)
{
	union {
		int i;
		char c;
	} u = { 1 };

	return u.c ? bswap32(hostlong) : hostlong;
}
