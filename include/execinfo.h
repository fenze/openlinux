#ifndef __EXECINFO_H
#define __EXECINFO_H

#include <sys/cdefs.h>

__BEGIN_DECLS

int backtrace(void *, int);
char **backtrace_symbols(void *const, int size);
void backtrace_symbols_fd(void *const, int, int);

__END_DECLS

#endif
