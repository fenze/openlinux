#include <__thread.h>

inline struct __thread_self *__thread_self(void)
{
	struct __thread_self *self;
	__asm__("mrs %0, tpidr_el0" : "=r"(self));
	return self;
}
