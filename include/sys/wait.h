#ifndef __WAIT_H
#define __WAIT_H

#define WCONTINUED	  0x00000008
#define WNOHANG		  0x00000001
#define WUNTRACED	  0x00000002
#define WCOREDUMP(__s)	  ((__s) & 0x80)
#define WIFCONTINUED(__s) ((__s) == 0xffff)
#define WIFEXITED(__s)	  (!WTERMSIG(__s))
#define WIFSIGNALED(__s)  (((s) & 0xffff) - 1U < 0xffu)
#define WIFSTOPPED(__s)	  ((short)((((__s) & 0xffff) * 0x10001U) >> 8) > 0x7f00)
#define WSTOPSIG(__s)	  WEXITSTATUS(__s)
#define WTERMSIG(__s)	  ((__s) & 0x7f)

#define WEXITED
#define WNOWAIT
#define WSTOPPED

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
