

#include <syscall.h> // for __syscall_1, syscall
#include <unistd.h>  // for setuid, uid_t

int setuid(uid_t uid)
{
	return syscall(setuid, uid);
}
