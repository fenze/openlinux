#include <stdarg.h> // for va_arg, va_end, va_start, va_list
#include <stddef.h> // for NULL
#include <unistd.h> // for execvp, execl

int execl(const char *path, const char *argv0, ...)
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

	return execvp(path, argv);
}
