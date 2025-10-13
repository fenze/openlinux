#ifndef __SYS_MSG_H
#define __SYS_MSG_H

#include <sys/ipc.h>

typedef __INT64_TYPE__ pid_t;
typedef __INT64_TYPE__ ssize_t;
typedef __INT64_TYPE__ time_t;
typedef __SIZE_TYPE__ size_t;
typedef unsigned long msglen_t;
typedef unsigned long msgqnum_t;

#define MSG_NOERROR 010000

struct msqid_ds {
	struct ipc_perm msg_perm;
	msgqnum_t msg_qnum;
	msglen_t msg_qbytes;
	pid_t msg_lspid;
	pid_t msg_lrpid;
	time_t msg_stime;
	time_t msg_rtime;
	time_t msg_ctime;
};

int msgctl(int, int, struct msqid_ds *);
int msgget(key_t, int);
ssize_t msgrcv(int, void *, size_t, long, int);
int msgsnd(int, const void *, size_t, int);

#endif
