


#include <syscall.h> // for __syscall_5, syscall
#include <unistd.h>  // for fchownat, gid_t, uid_t

int fchownat(int fd, const char *path, uid_t owner, gid_t group, int flag)
{
	return syscall(fchownat, fd, path, owner, group, flag);
}
