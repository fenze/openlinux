#include "asm/unistd_64.h" // for __NR_unlinkat
#include "errno.h"	   // for EISDIR, errno

#include <fcntl.h>   // for AT_FDCWD, AT_REMOVEDIR
#include <stdio.h>   // for remove
#include <syscall.h> // for __syscall_3, syscall

int remove(const char *path)
{
	if (syscall(unlinkat, AT_FDCWD, path, 0) < 0) {
		if (errno == EISDIR) {
			return syscall(unlinkat, AT_FDCWD, path, AT_REMOVEDIR);
		} else {
			return -1;
		}
	}

	return 0;
}
