#include <syscall.h> // for __syscall, __syscall_1

_Noreturn void _exit(int status)
{
	__syscall(exit, status);

	__builtin_unreachable();
}
