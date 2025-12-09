#include "asm/unistd_64.h" // for __NR_rename

#include <syscall.h> // for __syscall_2, syscall

int rename(const char *old, const char *new)
{
	return syscall(rename, old, new);
}
