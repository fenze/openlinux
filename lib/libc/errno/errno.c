#include <features.h>

int *__errno_location(void)
{
	static int errno = 0;
	return &errno;
}
