#include <string.h>
#include <unistd.h>
#include <sys/uio.h>

int main(int argc, char **argv)
{
	if (argc <= 1)
		return 0;

	struct iovec iov[2 * argc - 2];
	int iovcnt = 0;

	for (int i = 1; i < argc; i++) {
		iov[iovcnt].iov_base = argv[i];
		iov[iovcnt].iov_len = strlen(argv[i]);
		iovcnt++;

		if (i < argc - 1) {
			iov[iovcnt].iov_base = " ";
			iov[iovcnt].iov_len = 1;
			iovcnt++;
		}
	}

	iov[iovcnt].iov_base = "\n";
	iov[iovcnt].iov_len = 1;
	iovcnt++;

	return writev(STDOUT_FILENO, iov, iovcnt) < 0 ? 1 : 0;
}
