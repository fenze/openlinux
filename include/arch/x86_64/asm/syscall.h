#ifndef __ASM_SYSCALL_H
#define __ASM_SYSCALL_H

__attribute__((__always_inline__)) inline unsigned long __syscall0(long n)
{
	unsigned long ret;
	__asm__ volatile("syscall" : "=a"(ret) : "a"(n) : "rcx", "r11", "memory");
	return ret;
}

__attribute__((__always_inline__)) inline unsigned long __syscall1(long n, long a1)
{
	unsigned long ret;
	__asm__ __volatile__("syscall" : "=a"(ret) : "a"(n), "D"(a1) : "rcx", "r11", "memory");
	return ret;
}

__attribute__((__always_inline__)) inline unsigned long __syscall2(long n, long a1, long a2)
{
	unsigned long ret;
	__asm__ volatile("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2) : "rcx", "r11", "memory");
	return ret;
}

__attribute__((__always_inline__)) inline unsigned long __syscall3(long n, long a1, long a2, long a3)
{
	unsigned long ret;
	__asm__ volatile("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2), "d"(a3) : "rcx", "r11", "memory");
	return ret;
}

__attribute__((__always_inline__)) inline unsigned long __syscall4(long n, long a1, long a2, long a3, long a4)
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	__asm__ volatile("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2), "d"(a3), "r"(r10) : "rcx", "r11", "memory");
	return ret;
}

__attribute__((__always_inline__)) inline unsigned long __syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	register long r8 __asm__("r8") = a5;
	__asm__ volatile("syscall"
			 : "=a"(ret)
			 : "a"(n), "D"(a1), "S"(a2), "d"(a3), "r"(r10), "r"(r8)
			 : "rcx", "r11", "memory");
	return ret;
}

__attribute__((__always_inline__)) inline unsigned long __syscall6(long n, long a1, long a2, long a3, long a4, long a5,
								   long a6)
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	register long r8 __asm__("r8") = a5;
	register long r9 __asm__("r9") = a6;
	__asm__ volatile("syscall"
			 : "=a"(ret)
			 : "a"(n), "D"(a1), "S"(a2), "d"(a3), "r"(r10), "r"(r8), "r"(r9)
			 : "rcx", "r11", "memory");
	return ret;
}

__attribute__((__always_inline__)) inline unsigned long __syscall7(long n, long a1, long a2, long a3, long a4, long a5,
								   long a6, long a7)
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	register long r8 __asm__("r8") = a5;
	register long r9 __asm__("r9") = a6;
	register long r12 __asm__("r12") = a7;
	__asm__ volatile("syscall"
			 : "=a"(ret)
			 : "a"(n), "D"(a1), "S"(a2), "d"(a3), "r"(r10), "r"(r8), "r"(r9), "r"(r12)
			 : "rcx", "r11", "memory");
	return ret;
}

#endif
