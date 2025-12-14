#include <alloca.h>  // for alloca
#include <err.h>     // for errx
#include <string.h>  // for strlen
#include <sys/uio.h> // for iovec, writev
#include <unistd.h>  // for STDOUT_FILENO

int main(int argc, char **argv)
{
	struct iovec *iov;
	int n_iov;

	if (argc <= 1)
		return 0;

	iov = alloca(sizeof(struct iovec) * (int)(2 * argc));
	n_iov = 0;

	for (int i = 1; i < argc; i++) {
		iov[n_iov].iov_base = argv[i];
		iov[n_iov++].iov_len = strlen(argv[i]);

		if (i < argc - 1) {
			iov[n_iov].iov_base = " ";
			iov[n_iov++].iov_len = 1;
		}
	}

	iov[n_iov].iov_base = "\n";
	iov[n_iov++].iov_len = 1;

	if (writev(STDOUT_FILENO, iov, n_iov) < 0)
		err(1, "writev");

	return 0;
}
