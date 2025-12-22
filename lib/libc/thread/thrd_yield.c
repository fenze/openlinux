#include <sched.h>
#include <threads.h>

void thrd_yield(void)
{
	sched_yield();
}
