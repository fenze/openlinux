#include "stddef.h" // for NULL

#include <__stdio.h> // for __FILE
#include <errno.h>   // for EINVAL, errno
#include <fcntl.h>   // for O_RDONLY, O_CLOEXEC, O_WRONLY
#include <stdio.h>   // for FILE, fclose, fdopen, popen
#include <unistd.h>  // for close, dup2, _exit, execl, fork, pipe2, STDIN_F...

FILE *popen(const char *command, const char *mode)
{
	FILE *stream;
	int oflag;
	int pipefd[2];

	switch (*mode) {
	case 'r':
		oflag = O_RDONLY;
		break;
	case 'w':
		oflag = O_WRONLY;
		break;
	default:
		errno = EINVAL;
		return NULL;
	}

	if (pipe2(pipefd, O_CLOEXEC) < 0)
		return NULL;

	stream = fdopen(pipefd[oflag], mode);
	if (stream == NULL) {
		close(pipefd[0]);
		close(pipefd[1]);
		return NULL;
	}

	pid_t pid = fork();

	if (pid < 0) {
		close(pipefd[0]);
		close(pipefd[1]);
		fclose(stream);
		return NULL;
	}

	if (pid == 0) {
		if (oflag == O_RDONLY) {
			dup2(pipefd[1], STDOUT_FILENO);
			close(pipefd[0]);
			close(pipefd[1]);
		} else {
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			close(pipefd[1]);
		}
		execl("/bin/sh", "sh", "-c", command, (char *)0);
		_exit(127);
	} else {
		if (oflag == O_RDONLY) {
			close(pipefd[1]);
		} else {
			close(pipefd[0]);
		}

		__FILE(stream)->pid = pid;

		return stream;
	}
}
