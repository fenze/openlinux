#include <sys/sem.h>
#include <syscall.h>

int semget(key_t key, int nsems, int semflg)
{
	return syscall(semget, key, nsems, semflg);
}
