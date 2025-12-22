/*
 * x86_64 clone syscall trampoline
 *
 * Goal: provide a reliable way to run a C function in the child after the
 * clone(2) syscall, without depending on the parent's stack frame (which is
 * invalid in the child because the child starts with a new stack pointer).
 *
 * API (internal):
 *
 *   long __clone(long (*fn)(void *), void *arg,
 *               unsigned long flags, void *child_stack,
 *               int *ptid, void *newtls, int *ctid);
 *
 * This uses the raw Linux x86_64 clone syscall:
 *   long clone(unsigned long flags, void *child_stack,
 *              int *ptid, int *ctid, unsigned long newtls);
 *
 * Behavior:
 * - In the parent, returns child TID (> 0) or -errno (< 0).
 * - In the child, calls fn(arg) and then exits the thread/process via
 *   SYS_exit (does not return).
 *
 * Notes:
 * - We explicitly place (fn,arg) onto the child's new stack before issuing
 *   the syscall. On success in the child, we recover them from %rsp and call.
 * - This avoids relying on any locals from the parent frame.
 * - The stack is aligned to 16 bytes before the call into C.
 */

	.text
	.globl __clone
	.type  __clone, @function

__clone:
	/*
	 * SysV AMD64 calling convention:
	 *   fn          in %rdi
	 *   arg         in %rsi
	 *   flags       in %rdx
	 *   child_stack in %rcx
	 *   ptid        in %r8
	 *   newtls      in %r9
	 *   ctid        at 8(%rsp)
	 */
	movq 8(%rsp), %r10          /* r10 = ctid (7th arg from caller stack) */

	/* r11 = child_stack (we'll use it as our working "new sp") */
	movq %rcx, %r11

	/*
	 * Ensure 16-byte alignment for the eventual C call:
	 * We'll build the child's stack as:
	 *   [low]  fn (8)
	 *          arg (8)
	 *   [high]  <-- %rsp in child before call site
	 *
	 * We align first, then reserve 16 bytes.
	 */
	andq $-16, %r11
	subq $16, %r11

	/* Store fn and arg onto the child's stack */
	movq %rdi, 0(%r11)          /* fn  */
	movq %rsi, 8(%r11)          /* arg */

	/*
	 * Prepare registers for Linux x86_64 clone syscall:
	 *   rax = SYS_clone
	 *   rdi = flags
	 *   rsi = child_stack
	 *   rdx = ptid
	 *   r10 = ctid
	 *   r8  = newtls
	 */
	movq %rdx, %rdi             /* flags */
	movq %r11, %rsi             /* child_stack (new sp) */
	movq %r8,  %rdx             /* ptid */
	movq %r9,  %r8              /* newtls */
	/* r10 already holds ctid */

	movq $56, %rax              /* SYS_clone on x86_64 */
	syscall

	/* Parent: rax = child tid (>0) or -errno (<0) */
	testq %rax, %rax
	jnz 1f

	/* Child: rax == 0 */

	/* %rsp is already the child_stack we provided. Recover fn/arg from it. */
	movq 8(%rsp), %rdi          /* first arg to fn = arg */
	call *0(%rsp)               /* call fn(arg) */

	/*
	 * If fn returns, exit the thread/process.
	 * Use SYS_exit (60). Return value of fn is in %rax; pass as status in %rdi.
	 */
	movq %rax, %rdi
	movq $60, %rax              /* SYS_exit */
	syscall
	hlt                         /* should not reach */

1:
	ret

	.size __clone, .-__clone
