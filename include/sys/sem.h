#ifndef __SYS_SEM_H
#define __SYS_SEM_H

#include <stddef.h>
#include <sys/ipc.h>
#include <time.h>

#define SEM_UNDO 0x1000
#define GETNCNT	 14
#define GETPID	 11
#define GETVAL	 12
#define GETALL	 13
#define GETZCNT	 15
#define SETVAL	 16
#define SETALL	 17

typedef __INT64_TYPE__ pid_t;
typedef __SIZE_TYPE__ size_t;
typedef __INT64_TYPE__ time_t;
typedef __UINT32_TYPE__ uid_t;
typedef __UINT32_TYPE__ gid_t;
typedef __UINT32_TYPE__ mode_t;
typedef __INT32_TYPE__ key_t;

struct semid_ds {
	struct ipc_perm sem_perm;
	unsigned short sem_nsems;
	time_t sem_otime;
	time_t sem_ctime;
};

struct sembuf {
	unsigned short sem_num;
	short sem_op;
	short sem_flg;
};

int semctl(int, int, int, ...);
int semget(key_t, int, int);
int semop(int, struct sembuf *, size_t);

#endif
