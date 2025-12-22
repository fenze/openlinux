#include <__stdio.h>
#include <atomic.h>
#include <stdio.h>

int ftrylockfile(FILE *file)
{
	if (file == NULL)
		return -1;

	return atomic_flag_test_and_set_explicit(&file->lock, memory_order_acquire) ? 1 : 0;
}
