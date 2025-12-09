#include "asm/unistd_64.h" // for __NR_truncate

#include <syscall.h> // for __syscall_2, syscall
#include <unistd.h>  // for off_t, truncate

int truncate(const char *path, off_t length)
{
	return syscall(truncate, path, length);
}
