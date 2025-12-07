#ifndef __WAIT_H
#define __WAIT_H

#define __BITS_WAIT_H_
#include <bits/wait.h>

#define WCONTINUED 0x00000008
#define WEXITED	   0x00000004
#define WNOWAIT	   0x01000000
#define WSTOPPED   WUNTRACED

typedef __UINT32_TYPE__ id_t;
typedef __INT64_TYPE__ pid_t;
typedef __UINT32_TYPE__ uid_t;

union sigval {
	int sival_int;
	void *sival_ptr;
};

typedef struct {
	int si_signo;
	int si_code;
	int si_errno;
	pid_t si_pid;
	uid_t si_uid;
	void *si_addr;
	int si_status;
	union sigval si_value;
} siginfo_t;

typedef enum { P_ALL = 0, P_PID = 1, P_PGID = 2 } idtype_t;

pid_t wait(int *);
int waitid(idtype_t, id_t, siginfo_t *, int);
pid_t waitpid(pid_t, int *, int);

#endif
