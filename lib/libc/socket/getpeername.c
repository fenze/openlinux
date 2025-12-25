

#include <sys/socket.h> // for getpeername, socklen_t
#include <syscall.h>	// for __syscall_3, syscall

int getpeername(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len)
{
	return syscall(getpeername, socket, address, address_len);
}
