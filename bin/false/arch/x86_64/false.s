.globl _start

_start:
    mov $60, %rax
    mov $1, %rdi
    syscall
