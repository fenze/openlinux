#include <setjmp.h> // for longjmp, sigjmp_buf, siglongjmp

_Noreturn void siglongjmp(sigjmp_buf env, int val)
{
	longjmp(env, val);
}
