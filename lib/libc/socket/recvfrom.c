#include "asm/unistd_64.h" // for __NR_recvfrom

#include <sys/socket.h> // for recvfrom, socklen_t
#include <sys/types.h>	// for size_t, ssize_t
#include <syscall.h>	// for __syscall_6, syscall

ssize_t recvfrom(int socket, void *restrict buffer, size_t length, int flags,
		 struct sockaddr *restrict address,
		 socklen_t *restrict address_len)
{
	return syscall(recvfrom, socket, buffer, length, flags, address,
		       address_len);
}
