#ifndef __SETJMP_H
#define __SETJMP_H

#include <bits/setjmp.h>

typedef jmp_buf sigjmp_buf;

_Noreturn void longjmp(jmp_buf, int);
_Noreturn void siglongjmp(sigjmp_buf, int);

int setjmp(jmp_buf);
int sigsetjmp(sigjmp_buf, int);

#endif
