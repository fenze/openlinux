#include <unistd.h>
#include <syscall.h>

int getlogin_r(char *name, size_t namesize)
{
	(void)name;
	(void)namesize;
	// TODO
	return 0;
}
