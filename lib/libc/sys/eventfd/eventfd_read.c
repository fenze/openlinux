#include <sys/eventfd.h>
#include <syscall.h>
#include <unistd.h>

int eventfd_read(int fildes, eventfd_t *value)
{
	return (sizeof(*value) == read(fildes, value, sizeof(*value))) ? 0 : -1;
}
