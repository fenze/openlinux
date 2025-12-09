#include "asm/unistd_64.h" // for __NR_socketpair

#include <syscall.h> // for __syscall_4, syscall

int socketpair(int domain, int type, int protocol, int socket_vector[2])
{
	return syscall(socketpair, domain, type, protocol, socket_vector);
}
