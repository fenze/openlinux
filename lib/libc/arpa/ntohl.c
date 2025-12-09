#include <arpa/inet.h> // for ntohl
#include <byteswap.h>  // for bswap32
#include <stdint.h>    // for uint32_t

uint32_t ntohl(uint32_t netlong)
{
	union {
		int i;
		char c;
	} u = { 1 };

	return u.c ? bswap32(netlong) : netlong;
}
