#ifndef __STDDEF_H
#define __STDDEF_H

#ifndef NULL
#define NULL ((void *)0)
#endif

#if __STDC_VERSION__ >= 202311L
typedef typeof(nullptr) nullptr_t;
#endif

#ifndef offsetof
#define offsetof(__type, __member) __builtin_offsetof(__type, __member)
#endif

typedef __WCHAR_TYPE__ wchar_t;
typedef __SIZE_TYPE__ ptrdiff_t;
typedef __SIZE_TYPE__ size_t;
typedef __INT32_TYPE__ max_align_t;

#endif
