#include <arpa/inet.h> // for ntohs
#include <byteswap.h>  // for bswap16
#include <stdint.h>    // for uint16_t

uint16_t ntohs(uint16_t netshort)
{
	union {
		int i;
		char c;
	} u = { 1 };

	return u.c ? bswap16(netshort) : netshort;
}
