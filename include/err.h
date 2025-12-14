#ifndef __ERR_H
#define __ERR_H

#include <stdarg.h>
#include <sys/cdefs.h>

__dead void err(int eval, const char *fmt, ...);
__dead void errx(int eval, const char *fmt, ...);
__dead void verr(int eval, const char *fmt, va_list args);
__dead void verrx(int eval, const char *fmt, va_list args);

void warn(const char *fmt, ...);
void warnx(const char *fmt, ...);
void vwarn(const char *fmt, va_list args);
void vwarnx(const char *fmt, va_list args);

#endif
