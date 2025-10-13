#include <arpa/inet.h>
#include <byteswap.h>

uint16_t htons(uint16_t hostshort)
{
	union {
		int i;
		char c;
	} u = { 1 };

	return u.c ? bswap_16(hostshort) : hostshort;
}
