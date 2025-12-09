#ifndef __BITS_SIGINFO_H
#define __BITS_SIGINFO_H

#ifndef __BITS_SIGINFO_H_
#error "Internal header — include the public API header instead."
#else
#undef __BITS_SIGINFO_H_
#endif

#define __BITS_SIGEVENT_H_
#include <bits/sigevent.h>

typedef __UINT32_TYPE__ id_t;
typedef __INT64_TYPE__ pid_t;
typedef __UINT32_TYPE__ uid_t;

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

#endif
