#include <asm/vdso.h> // for __vdso_time
#include <time.h>     // for timespec, clock_gettime, time_t, CLOCK_REALTIME

time_t time(time_t *tloc)
{
	struct timespec ts;

#if defined(__x86_64__)
	if (__vdso_time)
		return __vdso_time(tloc);
#endif

	clock_gettime(CLOCK_REALTIME, &ts);

	if (tloc)
		*tloc = ts.tv_sec;

	return ts.tv_sec;
}
