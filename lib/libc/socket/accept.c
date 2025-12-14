

#include <sys/socket.h> // for accept, socklen_t
#include <syscall.h>	// for __syscall_3, syscall

int accept(int socket, struct sockaddr *restrict address,
	   socklen_t *restrict address_len)
{
	return syscall(accept, socket, address, address_len);
}
