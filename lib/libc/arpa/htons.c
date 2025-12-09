#include <arpa/inet.h> // for uint16_t, htons
#include <byteswap.h>  // for bswap16
#include <stdint.h>

uint16_t htons(uint16_t hostshort)
{
	union {
		int i;
		char c;
	} u = { 1 };

	return u.c ? bswap16(hostshort) : hostshort;
}
