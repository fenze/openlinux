

#include <stddef.h>
#include <sys/socket.h> // for sendto, socklen_t
#include <sys/types.h>	// for size_t, ssize_t
#include <syscall.h>	// for __syscall_6, syscall

ssize_t sendto(int socket, const void *message, size_t length, int flags,
	       const struct sockaddr *dest_addr, socklen_t dest_len)
{
	return syscall(sendto, socket, message, length, flags, dest_addr,
		       dest_len);
}
