#include <libc.h>

int isgraph(int c)
{
	return (unsigned)c - 0x21 < 0x5e;
}

weak_reference(isgraph, isgraph_l);
