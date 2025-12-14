

#include <syscall.h> // for __syscall_3, syscall

int socket(int domain, int type, int protocol)
{
	return syscall(socket, domain, type, protocol);
}
