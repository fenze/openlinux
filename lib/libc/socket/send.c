#include "asm/unistd_64.h" // for __NR_sendto

#include <sys/socket.h> // for send
#include <sys/types.h>	// for size_t, ssize_t
#include <syscall.h>	// for __syscall_6, syscall

ssize_t send(int socket, const void *buffer, size_t length, int flags)
{
	return syscall(sendto, socket, buffer, length, flags, 0, 0);
}
