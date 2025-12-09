#include <stddef.h>
#include <syscall.h> // for __syscall_2, syscall
#include <unistd.h>  // for getcwd, size_t

char *getcwd(char *buf, size_t size)
{
	return (char *)syscall(getcwd, buf, size);
}
