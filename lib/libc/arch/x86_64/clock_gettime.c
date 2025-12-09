#include "asm/unistd_64.h" // for __NR_clock_gettime

#include <asm/vdso.h> // for __vdso_clock_gettime
#include <syscall.h>  // for __syscall_2, syscall
#include <time.h>     // for clock_gettime, clockid_t

int clock_gettime(clockid_t clock_id, struct timespec *tp)
{
#if defined(__x86_64__)
	if (__vdso_clock_gettime)
		return __vdso_clock_gettime(clock_id, tp);
#endif

	return syscall(clock_gettime, clock_id, tp);
}
