


#include <syscall.h> // for __syscall_0, syscall
#include <unistd.h>  // for getgid, gid_t

gid_t getgid(void)
{
	return syscall(getgid);
}
