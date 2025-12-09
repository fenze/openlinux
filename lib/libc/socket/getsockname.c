


#include <sys/socket.h> // for getsockname, socklen_t
#include <syscall.h>	// for __syscall_3, syscall

int getsockname(int socket, struct sockaddr *restrict address,
		socklen_t *restrict address_len)
{
	return syscall(getsockname, socket, address, address_len);
}
