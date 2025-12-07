#include <sys/utsname.h>
#include <syscall.h>

int uname(struct utsname *name)
{
	return syscall(uname, name);
}
