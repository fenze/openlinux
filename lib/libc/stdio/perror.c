#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/uio.h>

void perror(const char *s)
{
	struct iovec iov[4];

	char *errstr = strerror(errno);

	if (s != NULL && *s != '\0') {
		iov[0].iov_base = (void *)s;
		iov[0].iov_len = strlen(s);
		iov[1].iov_base = ": ";
		iov[1].iov_len = 2;
	}

	iov[s != NULL && *s != '\0' ? 2 : 0].iov_base = errstr;
	iov[s != NULL && *s != '\0' ? 2 : 0].iov_len = strlen(errstr);
	iov[s != NULL && *s != '\0' ? 3 : 1].iov_base = "\n";
	iov[s != NULL && *s != '\0' ? 3 : 1].iov_len = 1;

	writev(STDERR_FILENO, iov, s != NULL && *s != '\0' ? 4 : 2);
}
