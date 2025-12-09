#include "asm/unistd_64.h" // for __NR_uname

#include <sys/utsname.h> // for uname
#include <syscall.h>	 // for __syscall_1, syscall

int uname(struct utsname *name)
{
	return syscall(uname, name);
}
