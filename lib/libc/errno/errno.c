#include <__thread.h>
#include <threads.h>

int *__errno(void)
{
	return &thrd_current()->terrno;
}
