#include <__thread.h>
#include <asm/prctl.h>
#include <elf.h>
#include <libc.h>
#include <string.h>
#include <sys/mman.h>
#include <syscall.h>

#define ALIGN_DOWN(x, a) ((x) & ~((a) - 1))
#define ALIGN_UP(x, a)	 (((x) + (a) - 1) & ~((a) - 1))

static struct tls __libc_tls = { 0 };
static struct __thread_self __libc_thread;
volatile int __libc_tid;

void __init_tls(void)
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

		if (tls_phdr->p_filesz > 0) {
			memcpy(tls_mem, (void *)tls_phdr->p_vaddr, tls_phdr->p_filesz);
			memset(tls_mem + tls_phdr->p_filesz, 0, tls_phdr->p_memsz - tls_phdr->p_filesz);
		} else {
			memset(tls_mem, 0, tls_phdr->p_memsz);
		}

		r = syscall(arch_prctl, ARCH_SET_FS, mem + sizeof(struct __thread_self));
		panic_if(r < 0, "arch_prctl(SET_FS) failed");
	} else {
		__libc.tls.base = NULL;
		thrd = &__libc_thread;
	}

	r = syscall(set_tid_address, &__libc_tid);
	panic_if(r < 0, "set_tid_address failed");
	thrd->tid = r;
}
