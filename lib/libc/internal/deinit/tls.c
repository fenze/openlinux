#include "stddef.h"
#include "sys/cdefs.h"
#include <libc.h>
#include <sys/mman.h>

void __libc_deinit_tls(void)
{
	int r;

	if (__libc.tls.base == NULL)
		return;

	r = munmap(__libc.tls.base, __libc.tls.size);
	panic_if(__predict_false(r < 0), "munmap(tls) failed");
}
