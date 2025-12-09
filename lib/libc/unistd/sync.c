


#include <syscall.h> // for __syscall_0, syscall

void sync(void)
{
	syscall(sync);
}
