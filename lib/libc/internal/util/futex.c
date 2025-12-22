#include <linux/futex.h>
#include <syscall.h>

int __futex_wait(volatile int *uaddr, int val)
{
	return syscall(futex, uaddr, FUTEX_WAIT | FUTEX_PRIVATE_FLAG, val, 0, 0, 0);
}

int __futex_wake(volatile int *uaddr, int n)
{
	/* futex(uaddr, FUTEX_WAKE, val=n, ...) */
	return syscall(futex, uaddr, FUTEX_WAKE | FUTEX_PRIVATE_FLAG, n, 0, 0, 0);
}
