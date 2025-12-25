#include <syscall.h>

int io_uring_register(unsigned int fd, unsigned int opcode, void *arg, unsigned int nr_args)
{
	return syscall(io_uring_register, fd, opcode, arg, nr_args);
}
