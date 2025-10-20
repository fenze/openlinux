#ifndef __NET_IF_H__
#define __NET_IF_H__

struct if_nameindex {
	unsigned if_index;
	char *if_name;
};

#define IF_NAMESIZE 16

void if_freenameindex(struct if_nameindex *);
char *if_indextoname(unsigned, char *);
struct if_nameindex *if_nameindex(void);
unsigned if_nametoindex(const char *);

#endif
