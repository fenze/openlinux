#include <__thread.h>
#include <threads.h>

thread_local struct __thread_self __thread_self;

thrd_t thrd_current(void)
{
	return &__thread_self;
}
