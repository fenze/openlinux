#include <arpa/inet.h>
#include <byteswap.h>

uint16_t ntohs(uint16_t netshort)
{
	union {
		int i;
		char c;
	} u = { 1 };

	return u.c ? bswap16(netshort) : netshort;
}
