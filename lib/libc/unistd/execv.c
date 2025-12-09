#include "asm/unistd_64.h" // for __NR_execve

#include <syscall.h> // for __syscall_3, syscall
#include <unistd.h>  // for execv

extern char **environ;

int execv(const char *path, char *const argv[])
{
	return syscall(execve, path, argv, environ);
}
