#include <__stdio.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>

int ftrylockfile(struct __FILE *file)
{
	if (file == NULL)
		return -1;

	return atomic_flag_test_and_set_explicit(&file->lock, memory_order_acquire) ? 1 : 0;
}
