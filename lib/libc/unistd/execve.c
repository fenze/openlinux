#include <syscall.h>

int execve(const char *file, char *const argv[], char *const envp[])
{
	return syscall(execve, file, argv, envp);
}
