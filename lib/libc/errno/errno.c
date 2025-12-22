#include <__thread.h>
#include <libc.h>

#include <threads.h>

/* Ensure TLS is initialized if errno is used */
extern void __init_tls(void);
void *__force_tls_init = (void *) __init_tls;

int *__errno(void)
{
	return &thrd_current()->errno_v;
}
