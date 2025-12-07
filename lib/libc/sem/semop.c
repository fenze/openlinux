#include <sys/sem.h>
#include <syscall.h>

int semop(int semid, struct sembuf *sops, size_t nsops)
{
	return syscall(semop, semid, sops, nsops);
}
