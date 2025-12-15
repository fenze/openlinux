// https://pubs.opengroup.org/onlinepubs/9799919799/basedefs/netinet_tcp.h.html

#include "core.h"

#include <netinet/tcp.h>

TEST(netinet_tcp_h)
{
	MACRO(TCP_NODELAY);
}
