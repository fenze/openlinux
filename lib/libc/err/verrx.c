#include "sys/cdefs.h"
#include <err.h>
#include <stdarg.h>
#include <stdlib.h>

__dead void verr(int eval, const char *fmt, va_list args)
{
	vwarn(fmt, args);
	exit(eval);
}
