#include <arpa/inet.h>
#include <byteswap.h>

uint32_t ntohl(uint32_t netlong)
{
	union {
		int i;
		char c;
	} u = { 1 };

	return u.c ? bswap32(netlong) : netlong;
}
