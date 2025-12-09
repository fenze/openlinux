#include "asm/unistd_64.h" // for __NR_recvfrom

#include <sys/socket.h> // for recv
#include <sys/types.h>	// for size_t, ssize_t
#include <syscall.h>	// for __syscall_6, syscall

ssize_t recv(int socket, void *buffer, size_t length, int flags)
{
	return syscall(recvfrom, socket, buffer, length, flags, 0, 0);
}
