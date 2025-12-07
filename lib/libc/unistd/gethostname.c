#include <unistd.h>
#include <syscall.h>

int gethostname(char *name, size_t namelen)
{
	(void)name;
	(void)namelen;
	// TODO
	return 0;
}
