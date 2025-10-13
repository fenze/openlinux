#ifndef __SYS_IPC_H
#define __SYS_IPC_H

#define IPC_CREAT 00001000
#define IPC_EXCL 00002000
#define IPC_NOWAIT 00004000

#define IPC_PRIVATE ((key_t)0)

#define IPC_RMID 0
#define IPC_SET 1
#define IPC_STAT 2

typedef __UINT32_TYPE__ uid_t;
typedef __UINT32_TYPE__ gid_t;
typedef __UINT32_TYPE__ mode_t;
typedef __INT32_TYPE__ key_t;

struct ipc_perm {
	uid_t uid;
	gid_t gid;
	uid_t cuid;
	gid_t cgid;
	mode_t mode;
};

key_t ftok(const char *, int);

#endif
