#include <unistd.h>
#include <syscall.h>

int getentropy(void *buffer, size_t length)
{
	(void)buffer;
	(void)length;
	// TODO
	return 0;
}
