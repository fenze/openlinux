.globl _start

_start:
    mov $162, %rax
    syscall

    mov $60, %rax
    xor %rdi, %rdi
    syscall
