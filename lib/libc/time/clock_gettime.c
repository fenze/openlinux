#include <asm/vdso.h>
#include <syscall.h>
#include <time.h>

extern void __libc_init_vdso(void);
void *__libc_force_vdso_init = (void *) __libc_init_vdso;

int clock_gettime(clockid_t clock_id, struct timespec *tp)
{
#if defined(__VDSO_CLOCK_GETTIME)
	if (__vdso_clock_gettime)
		return __vdso_clock_gettime(clock_id, tp);
#endif

	return syscall(clock_gettime, clock_id, tp);
}
