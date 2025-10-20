// https://pubs.opengroup.org/onlinepubs/9799919799/basedefs/net_if.h.html

#include "core.h"

#include <net/if.h>

TEST(net_if_h)
{
	TYPE(struct if_nameindex);
	STRUCT_MEMBER(struct if_nameindex, unsigned, if_index);
	STRUCT_MEMBER(struct if_nameindex, char *, if_name);

	MACRO(IF_NAMESIZE);

	FUNCTION(if_freenameindex, FN(void, struct if_nameindex *));
	FUNCTION(if_indextoname, FN(char *, unsigned, char *));
	FUNCTION(if_nameindex, FN(struct if_nameindex *));
	FUNCTION(if_nametoindex, FN(unsigned, const char *));
}
