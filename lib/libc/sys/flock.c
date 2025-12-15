#include <syscall.h>

int flock(int fildes, int opcode)
{
	return syscall(flock, fildes, opcode);
}
