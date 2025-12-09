#include <unistd.h> // for lockf, off_t

int lockf(int fildes, int function, off_t size)
{
	(void)fildes;
	(void)function;
	(void)size;
	// TODO
	return 0;
}
