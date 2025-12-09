


#include <syscall.h> // for __syscall_3, syscall
#include <unistd.h>  // for seteuid, uid_t

int seteuid(uid_t uid)
{
	return syscall(setresuid, -1, uid, -1);
}
