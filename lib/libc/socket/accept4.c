


#include <sys/socket.h> // for accept4, socklen_t
#include <syscall.h>	// for __syscall_4, syscall

int accept4(int socket, struct sockaddr *restrict address,
	    socklen_t *restrict address_len, int flag)
{
	return syscall(accept4, socket, address, address_len, flag);
}
