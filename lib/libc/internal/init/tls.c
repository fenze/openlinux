#include <__thread.h>
#include <asm/prctl.h>
#include <elf.h>
#include <libc.h>
#include <string.h>
#include <sys/mman.h>
#include <syscall.h>

#include <libc/tcb.h>

#include <stdio.h>

// TODO: remove this thing
static struct tls __libc_tls = { 0 };

static struct __thread_self __libc_thread;
volatile int __libc_tid;

void __libc_tls_copy(void *dest)
{
	if (__libc_tls.size == 0)
		return;

	if (__libc_tls.length > 0) {
		memcpy(dest, __libc_tls.data, __libc_tls.length);

		memset((unsigned char *)dest + __libc_tls.length, 0, __libc_tls.size - __libc_tls.length);
	} else {
		memset(dest, 0, __libc_tls.size);
	}
}

void __libc_init_tls(void)
{
	int r;
	void *mem;
	size_t base;
	unsigned char *p;
	Elf64_Phdr *tls_phdr;
	struct __thread_self *thrd;

	base = 0;
	tls_phdr = 0;
	p = (void *)__libc.auxv[AT_PHDR];
	for (size_t n = __libc.auxv[AT_PHNUM]; n > 0; n--, p += __libc.auxv[AT_PHENT]) {
		Elf64_Phdr *phdr = (Elf64_Phdr *)p;

		if (phdr->p_type == PT_PHDR) {
			base = __libc.auxv[AT_PHDR] - phdr->p_vaddr;
		} else if (phdr->p_type == PT_TLS) {
			tls_phdr = phdr;
		}
	}

	if (tls_phdr) {
		__libc_tls.data = (void *)(base + tls_phdr->p_vaddr);
		__libc_tls.length = tls_phdr->p_filesz;
		__libc_tls.size = tls_phdr->p_memsz;
		__libc_tls.align = tls_phdr->p_align;
		__libc.tls.align = __libc_tls.align;
	}

	if (__libc_tls.size != 0) {
		void *tls_mem;
		size_t tls_size = __libc_tls.size + sizeof(struct __thread_self);
		tls_size = (tls_size + __libc_tls.align - 1) & ~(__libc_tls.align - 1);

		mem = mmap(0, tls_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		panic_if(mem == MAP_FAILED, "mmap failed");

		__libc.tls.base = mem;
		__libc.tls.size = tls_size;

		thrd = (struct __thread_self *)mem;
		tls_mem = (unsigned char *)mem + sizeof(struct __thread_self);

		__libc_tls_copy(tls_mem);

		__libc.tls.base = tls_mem;
		__libc.tls.size = __libc_tls.size;
	} else {
		thrd = &__libc_thread;
		__libc.tls.base = &__libc_thread;
		__libc.tls.size = 0;
	}

	r = syscall(set_tid_address, &__libc_tid);
	panic_if(r < 0, "set_tid_address failed");

	thrd->self = thrd;
	thrd->tid = r;
	thrd->dtv = NULL;

	__libc_tcb_set((uint64_t)thrd);
}
