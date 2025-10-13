#include <unistd.h>
#include <syscall.h>

char *getcwd(char *buf, size_t size)
{
	return (char *)syscall(getcwd, buf, size);
}
