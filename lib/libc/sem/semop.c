


#include <stddef.h>
#include <sys/sem.h> // for semop, size_t
#include <syscall.h> // for __syscall_3, syscall

int semop(int semid, struct sembuf *sops, size_t nsops)
{
	return syscall(semop, semid, sops, nsops);
}
