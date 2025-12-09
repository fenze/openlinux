#include <__thread.h> // for __thread_self
#include <threads.h>  // for thrd_current, thrd_t

thrd_t thrd_current(void)
{
	static _Thread_local struct __thread_self self = { 0 };
	return &self;
}
