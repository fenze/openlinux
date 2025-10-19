#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	const char *out;
	struct iovec iov[2];
	char opt, mode = 'L';
	char cwd[PATH_MAX];

	while ((opt = getopt(argc, argv, "")) != -1) {
		switch (opt) {
		case 'L':
		case 'P':
			mode = opt;
			break;
		default:
			write(STDERR_FILENO, "usage: pwd [-L|-P]\n", 20);
			return 1;
		}
	}

	if (getcwd(cwd, sizeof(cwd)) == NULL) {
		perror("pwd: getcwd");
		return 1;
	}

	if (mode == 'L') {
		const char *pwd;
		struct stat cst, pst;

		if ((pwd = getenv("PWD")) == NULL || *pwd != '/' ||
		    stat(pwd, &pst) < 0) {
			out = cwd;
		}

		if (stat(cwd, &cst) < 0) {
			perror("pwd: stat");
		}

		out = (pst.st_dev == cst.st_dev && pst.st_ino == cst.st_ino) ?
			      pwd :
			      cwd;
	}

	iov[0].iov_base = (char *)out;
	iov[0].iov_len = strlen(out);

	iov[1].iov_base = "\n";
	iov[1].iov_len = 1;

	writev(STDOUT_FILENO, iov, 2);

	return 0;
}
