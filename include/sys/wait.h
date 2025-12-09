#ifndef __WAIT_H
#define __WAIT_H

#define __BITS_WAIT_H_
#include <bits/wait.h>

#define __BITS_SIGINFO_H_
#include <bits/siginfo.h>

struct rusage;

#define WCONTINUED 0x00000008
#define WEXITED	   0x00000004
#define WNOWAIT	   0x01000000
#define WSTOPPED   WUNTRACED

typedef enum { P_ALL = 0, P_PID = 1, P_PGID = 2 } idtype_t;

pid_t wait(int *);
pid_t wait3(int *, int, struct rusage *);
int waitid(idtype_t, id_t, siginfo_t *, int);
pid_t waitpid(pid_t, int *, int);

#endif
