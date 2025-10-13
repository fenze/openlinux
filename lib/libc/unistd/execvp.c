#include <syscall.h>

extern char **environ;

int execvp(const char *file, char *const argv[])
{
	return syscall(execve, file, argv, environ);
}
