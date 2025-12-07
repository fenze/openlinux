#include <stdarg.h>
#include <unistd.h>

int execlp(const char *path, const char *argv0, ...)
{
	int argc;
	va_list ap;
	va_start(ap, argv0);

	argc = 1;
	while (va_arg(ap, const char *) != NULL) {
		argc++;
	}
	va_end(ap);

	char *argv[argc + 1];
	va_start(ap, argv0);
	for (int i = 1; i < argc; i++) {
		argv[i] = (char *)va_arg(ap, const char *);
	}
	argv[argc] = NULL;
	va_end(ap);

	return execve(path, argv, 0);
}
