#include <asm/vdso.h>
#include <time.h>

time_t time(time_t *tloc)
{
	struct timespec ts;

#if defined(__VDSO_TIME)
	if (__vdso_time)
		return __vdso_time(tloc);
#endif

	clock_gettime(CLOCK_REALTIME, &ts);

	if (tloc)
		*tloc = ts.tv_sec;

	return ts.tv_sec;
}
