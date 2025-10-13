#include <setjmp.h>

_Noreturn void siglongjmp(sigjmp_buf env, int val)
{
	longjmp(env, val);
}
