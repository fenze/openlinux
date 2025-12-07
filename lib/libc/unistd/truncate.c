#include <unistd.h>
#include <syscall.h>

int truncate(const char *path, off_t length)
{
	return syscall(truncate, path, length);
}
