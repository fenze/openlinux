#include "asm/unistd_64.h" // for __NR_semget

#include <sys/sem.h>   // for semget
#include <sys/types.h> // for key_t
#include <syscall.h>   // for __syscall_3, syscall

int semget(key_t key, int nsems, int semflg)
{
	return syscall(semget, key, nsems, semflg);
}
