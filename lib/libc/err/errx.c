#include "sys/cdefs.h"
#include <err.h>
#include <stdarg.h>

__dead void errx(int eval, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	verrx(eval, fmt, ap);
	va_end(ap);
}
