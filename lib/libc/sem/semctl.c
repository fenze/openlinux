#include "asm/unistd_64.h" // for __NR_semctl

#include <stdarg.h>  // for va_arg, va_end, va_list, va_start
#include <stddef.h>  // for NULL
#include <sys/ipc.h> // for IPC_SET, IPC_STAT
#include <sys/sem.h> // for GETALL, SETALL, SETVAL, semctl
#include <syscall.h> // for __syscall_4, syscall

int semctl(int semid, int semnum, int cmd, ...)
{
	va_list ap;
	struct semid_ds *buf = NULL;

	switch (cmd) {
	case SETVAL:
	case GETALL:
	case SETALL:
	case IPC_SET:
	case IPC_STAT:
		va_start(ap, cmd);
		buf = va_arg(ap, struct semid_ds *);
		va_end(ap);
	}

	return syscall(semctl, semid, semnum, cmd, buf);
}
