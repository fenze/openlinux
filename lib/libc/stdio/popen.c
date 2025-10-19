#include <io.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

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
	} else if (pid == 0) {
		if (oflag == O_RDONLY) {
			dup2(pipefd[1], STDOUT_FILENO);
			close(pipefd[0]);
			close(pipefd[1]);
		} else {
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			close(pipefd[1]);
		}
		execl("/bin/sh", "sh", "-c", command, (char *)NULL);
		_exit(127);
	} else {
		if (oflag == O_RDONLY) {
			close(pipefd[1]);
		} else {
			close(pipefd[0]);
		}

		stream->pid = pid;

		return stream;
	}
}
