#include <err.h>
#include <stdarg.h>

__dead void err(int eval, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	verr(eval, fmt, ap);
	va_end(ap);
}
