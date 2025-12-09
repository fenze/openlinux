#include "asm/unistd_64.h" // for __NR_dup3

#include <syscall.h> // for __syscall_3, syscall

int dup3(int fildes, int fildes2, int flag)
{
	return syscall(dup3, fildes, fildes2, flag);
}
