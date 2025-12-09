#include "__stdio.h"   // for __FILE, __libc_fadd
#include "features.h"  // for __weak
#include "stdatomic.h" // for ATOMIC_FLAG_INIT, atomic_flag

#include <atomic.h> // for LIBC_LOCK, LIBC_UNLOCK
#include <fcntl.h>  // for O_WRONLY
#include <stddef.h> // for NULL
#include <stdio.h>  // for stdout
#include <unistd.h> // for STDOUT_FILENO

#define BUFSIZ 4096

__weak char __stdout_buffer[0];
static atomic_flag __stdio_lock = ATOMIC_FLAG_INIT;
struct __FILE __stdout = { .fd = STDOUT_FILENO,
			   .flags = O_WRONLY,
			   .type = 1,
			   .buf = __stdout_buffer,
			   .buf_len = 0,
			   .buf_size = BUFSIZ,
			   .buf_pos = 0,
			   .eof = 0,
			   .unget_cnt = 0,
			   .offset = 0,
			   .next = NULL,
			   .lock = ATOMIC_FLAG_INIT };

struct __FILE *const stdout = (struct __FILE *)&__stdout;

void __libc_fadd(struct __FILE *f)
{
	LIBC_LOCK(__stdio_lock);
	struct __FILE *cur = &__stdout;
	while (cur->next)
		cur = cur->next;
	cur->next = f;
	LIBC_UNLOCK(__stdio_lock);
}
