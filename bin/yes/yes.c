#include <string.h>
#include <sys/uio.h>

int main(int argc, char **argv)
{
	char *str;
	struct iovec iov[2];

	str = (argc > 1) ? argv[1] : "y";

	iov[0].iov_base = str;
	iov[0].iov_len = strlen(str);

	iov[1].iov_base = "\n";
	iov[1].iov_len = 1;

	while (1) {
		writev(1, iov, 2);
	}

	return 0;
}
