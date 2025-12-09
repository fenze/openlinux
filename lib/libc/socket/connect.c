


#include <sys/socket.h> // for connect, socklen_t
#include <syscall.h>	// for __syscall_3, syscall

int connect(int socket, const struct sockaddr *address, socklen_t address_len)
{
	return syscall(connect, socket, address, address_len);
}
