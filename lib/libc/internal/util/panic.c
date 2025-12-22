#include <string.h>
#include <sys/cdefs.h>
#include <sys/uio.h>
#include <unistd.h>

__dead void __libc_panic(const char *prefix, const char *f, const char *errmsg)
{
	struct iovec iovec[5];
	const char *e = "libc panic: ";

	iovec[0].iov_base = (char *)e;
	iovec[0].iov_len = sizeof("libc panic: ") - 1;

	iovec[1].iov_base = (char *)prefix;
	iovec[1].iov_len = strlen(prefix);

	iovec[2].iov_base = (char *)f;
	iovec[2].iov_len = strlen(f);

	iovec[3].iov_base = (char *)errmsg;
	iovec[3].iov_len = strlen(errmsg);

	iovec[4].iov_base = "\n";
	iovec[4].iov_len = 1;

	writev(STDERR_FILENO, iovec, 5);

	__builtin_trap();
}
