#pragma once

#ifdef NDEBUG
#define assert(ignore) ((void)0)
#else

#define assert(__expr) ((__expr) ? (void)0 : __assert(__FILE__, __LINE__, __PRETTY_FUNCTION__, #__expr))

_Noreturn void __assert(const char *_Nonnull __file, int __line, const char *_Nonnull __func,
			const char *_Nonnull __expr);
#endif
