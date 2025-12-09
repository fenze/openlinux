#include "asm/unistd_64.h" // for __NR_exit

#include <syscall.h> // for __syscall, __syscall_1

void _exit(int status)
{
	__syscall(exit, status);
	__builtin_unreachable();
}
