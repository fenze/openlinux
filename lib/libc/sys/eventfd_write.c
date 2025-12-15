#include <sys/eventfd.h>
#include <syscall.h>
#include <unistd.h>

int eventfd_write(int fildes, eventfd_t value)
{
	return (sizeof(value) == write(fildes, &value, sizeof(value))) ? 0 : -1;
}
