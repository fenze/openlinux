#include "asm/unistd_64.h" // for __NR_execve

#include <syscall.h> // for __syscall_3, syscall

int execve(const char *file, char *const argv[], char *const envp[])
{
	return syscall(execve, file, argv, envp);
}
