#include <__thread.h>

#include <threads.h>

extern void __libc_init_tls(void);
void *__libc_force_init_tls = (void *)__libc_init_tls;

extern void __libc_deinit_tls(void);
void *__libc_force_deinit_tls = (void *)__libc_deinit_tls;

int *__errno(void)
{
	return &thrd_current()->errno_v;
}
