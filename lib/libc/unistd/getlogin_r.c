#include <stddef.h>
#include <unistd.h> // for getlogin_r, size_t

int getlogin_r(char *name, size_t namesize)
{
	(void)name;
	(void)namesize;
	// TODO
	return 0;
}
