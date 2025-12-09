#include <stddef.h>
#include <unistd.h> // for getentropy, size_t

int getentropy(void *buffer, size_t length)
{
	(void)buffer;
	(void)length;
	// TODO
	return 0;
}
