#ifndef __LIBC_STDIO_H__
#define __LIBC_STDIO_H__

#include <stdatomic.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef __SIZE_TYPE__ size_t;

#define _IO_ERR	 0x4
#define _IO_EOF	 0x8
#define _IO_WIDE 0x10

struct __FILE {
	int fd;
	uint32_t flags;
	int type;
	pid_t pid;
	atomic_flag lock;
	char *buf;
	int eof;
	size_t buf_size;
	size_t buf_pos;
	size_t buf_len;
	unsigned char unget_buf[16];
	size_t unget_cnt;
	off_t offset;
	struct __FILE *next;
};

#define __FILE(__stream) ((struct __FILE *)(__stream))

void __libc_fadd(struct __FILE *f);

#endif
