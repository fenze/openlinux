#include <arpa/inet.h>
#include <byteswap.h>

uint32_t htonl(uint32_t hostlong)
{
	union {
		int i;
		char c;
	} u = { 1 };

	return u.c ? bswap_32(hostlong) : hostlong;
}
