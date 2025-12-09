#include "asm/unistd_64.h" // for __NR_semop

#include <sys/sem.h> // for semop, size_t
#include <syscall.h> // for __syscall_3, syscall

int semop(int semid, struct sembuf *sops, size_t nsops)
{
	return syscall(semop, semid, sops, nsops);
}
