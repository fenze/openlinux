#include <setjmp.h> // for sigsetjmp, sigjmp_buf

int sigsetjmp(sigjmp_buf env, int savemask)
{
	__asm__ __volatile__("movq %%rbx, 0(%0)\n"
			     "movq %%rbp, 8(%0)\n"
			     "movq %%r12, 16(%0)\n"
			     "movq %%r13, 24(%0)\n"
			     "movq %%r14, 32(%0)\n"
			     "movq %%r15, 40(%0)\n"

			     "leaq 8(%%rsp), %%rax\n"
			     "movq %%rax, 48(%0)\n"
			     "movq (%%rsp), %%rax\n"
			     "movq %%rax, 56(%0)\n"

			     "testl %%esi, %%esi\n"
			     "jz 1f\n"
			     "movq $2, %%rdi\n"
			     "movq $0, %%rsi\n"
			     "leaq 64(%0), %%rdx\n"
			     "movq $128, %%r10\n"
			     "movq $14, %%rax\n"
			     "syscall\n"

			     "1:\n"
			     "xor %%eax, %%eax\n"
			     :
			     : "r"(env), "S"(savemask)
			     : "rax", "rdi", "rdx", "r10", "memory");

	return 0;
}
