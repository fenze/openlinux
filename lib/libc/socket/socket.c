#include "asm/unistd_64.h" // for __NR_socket

#include <syscall.h> // for __syscall_3, syscall

int socket(int domain, int type, int protocol)
{
	return syscall(socket, domain, type, protocol);
}
