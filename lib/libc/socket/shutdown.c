#include "asm/unistd_64.h" // for __NR_shutdown

#include <syscall.h> // for __syscall_2, syscall

int shutdown(int socket, int how)
{
	return syscall(shutdown, socket, how);
}
