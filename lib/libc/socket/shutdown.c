

#include <syscall.h> // for __syscall_2, syscall

int shutdown(int socket, int how)
{
	return syscall(shutdown, socket, how);
}
