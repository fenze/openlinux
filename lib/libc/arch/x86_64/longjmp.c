#include <setjmp.h>

_Noreturn void longjmp(jmp_buf env, int val)
{
	__asm__ __volatile__("xor %eax,%eax\n"
			     "cmp $1,%esi\n"
			     "adc %esi,%eax\n"
			     "mov (%rdi),%rbx\n"
			     "mov 8(%rdi),%rbp\n"
			     "mov 16(%rdi),%r12\n"
			     "mov 24(%rdi),%r13\n"
			     "mov 32(%rdi),%r14\n"
			     "mov 40(%rdi),%r15\n"
			     "mov 48(%rdi),%rsp\n"
			     "jmp *56(%rdi)\n");

	__builtin_unreachable();
}
