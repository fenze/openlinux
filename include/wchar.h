#ifndef __WCHAR_H__
#define __WCHAR_H__

typedef struct __FILE FILE;
typedef struct __locale_t *locale_t;
typedef struct __mbstate_t mbstate_t;
typedef __SIZE_TYPE__ size_t;
typedef __builtin_va_list va_list;
typedef __WCHAR_TYPE__ wchar_t;
typedef unsigned wint_t;
struct tm;

#undef WCHAR_MAX
#undef WCHAR_MIN
#if L'\0' - 1 > 0
#define WCHAR_MAX (0xffffffffu + L'\0')
#define WCHAR_MIN (0 + L'\0')
#else
#define WCHAR_MAX (0x7fffffff + L'\0')
#define WCHAR_MIN (-1 - 0x7fffffff + L'\0')
#endif

#undef WEOF
#define WEOF 0xffffffffU

#undef NULL
#define NULL ((void *)0)

wint_t btowc(int);
wint_t fgetwc(FILE *);
wchar_t *fgetws(wchar_t *restrict, int, FILE *restrict);
wint_t fputwc(wchar_t, FILE *);
int fputws(const wchar_t *restrict, FILE *restrict);
int fwide(FILE *, int);
int fwprintf(FILE *restrict, const wchar_t *restrict, ...);
int fwscanf(FILE *restrict, const wchar_t *restrict, ...);
wint_t getwc(FILE *);
wint_t getwchar(void);
size_t mbrlen(const char *restrict, size_t, mbstate_t *restrict);
size_t mbrtowc(wchar_t *restrict, const char *restrict, size_t,
	       mbstate_t *restrict);
int mbsinit(const mbstate_t *);
size_t mbsnrtowcs(wchar_t *restrict, const char **restrict, size_t, size_t,
		  mbstate_t *restrict);
size_t mbsrtowcs(wchar_t *restrict, const char **restrict, size_t,
		 mbstate_t *restrict);
FILE *open_wmemstream(wchar_t **, size_t *);
wint_t putwc(wchar_t, FILE *);
wint_t putwchar(wchar_t);
int swprintf(wchar_t *restrict, size_t, const wchar_t *restrict, ...);
int swscanf(const wchar_t *restrict, const wchar_t *restrict, ...);
wint_t ungetwc(wint_t, FILE *);
int vfwprintf(FILE *restrict, const wchar_t *restrict, va_list);
int vfwscanf(FILE *restrict, const wchar_t *restrict, va_list);
int vswprintf(wchar_t *restrict, size_t, const wchar_t *restrict, va_list);
int vswscanf(const wchar_t *restrict, const wchar_t *restrict, va_list);
int vwprintf(const wchar_t *restrict, va_list);
int vwscanf(const wchar_t *restrict, va_list);
wchar_t *wcpcpy(wchar_t *restrict, const wchar_t *restrict);
wchar_t *wcpncpy(wchar_t *restrict, const wchar_t *restrict, size_t);
size_t wcrtomb(char *restrict, wchar_t, mbstate_t *restrict);
int wcscasecmp(const wchar_t *, const wchar_t *);
int wcscasecmp_l(const wchar_t *, const wchar_t *, locale_t);
wchar_t *wcscat(wchar_t *restrict, const wchar_t *restrict);
wchar_t *wcschr(const wchar_t *, wchar_t);
int wcscmp(const wchar_t *, const wchar_t *);
int wcscoll(const wchar_t *, const wchar_t *);
int wcscoll_l(const wchar_t *, const wchar_t *, locale_t);
wchar_t *wcscpy(wchar_t *restrict, const wchar_t *restrict);
size_t wcscspn(const wchar_t *, const wchar_t *);
wchar_t *wcsdup(const wchar_t *);
size_t wcsftime(wchar_t *restrict, size_t, const wchar_t *restrict,
		const struct tm *restrict);
size_t wcslcat(wchar_t *restrict, const wchar_t *restrict, size_t);
size_t wcslcpy(wchar_t *restrict, const wchar_t *restrict, size_t);
size_t wcslen(const wchar_t *);
int wcsncasecmp(const wchar_t *, const wchar_t *, size_t);
int wcsncasecmp_l(const wchar_t *, const wchar_t *, size_t, locale_t);
wchar_t *wcsncat(wchar_t *restrict, const wchar_t *restrict, size_t);
int wcsncmp(const wchar_t *, const wchar_t *, size_t);
wchar_t *wcsncpy(wchar_t *restrict, const wchar_t *restrict, size_t);
size_t wcsnlen(const wchar_t *, size_t);
size_t wcsnrtombs(char *restrict, const wchar_t **restrict, size_t, size_t,
		  mbstate_t *restrict);
wchar_t *wcspbrk(const wchar_t *, const wchar_t *);
wchar_t *wcsrchr(const wchar_t *, wchar_t);
size_t wcsrtombs(char *restrict, const wchar_t **restrict, size_t,
		 mbstate_t *restrict);
size_t wcsspn(const wchar_t *, const wchar_t *);
wchar_t *wcsstr(const wchar_t *restrict, const wchar_t *restrict);
double wcstod(const wchar_t *restrict, wchar_t **restrict);
float wcstof(const wchar_t *restrict, wchar_t **restrict);
wchar_t *wcstok(wchar_t *restrict, const wchar_t *restrict, wchar_t **restrict);
long wcstol(const wchar_t *restrict, wchar_t **restrict, int);
long double wcstold(const wchar_t *restrict, wchar_t **restrict);
long long wcstoll(const wchar_t *restrict, wchar_t **restrict, int);
unsigned long wcstoul(const wchar_t *restrict, wchar_t **restrict, int);
unsigned long long wcstoull(const wchar_t *restrict, wchar_t **restrict, int);
int wcswidth(const wchar_t *, size_t);
size_t wcsxfrm(wchar_t *restrict, const wchar_t *restrict, size_t);
size_t wcsxfrm_l(wchar_t *restrict, const wchar_t *restrict, size_t, locale_t);
int wctob(wint_t);
int wcwidth(wchar_t);
wchar_t *wmemchr(const wchar_t *, wchar_t, size_t);
int wmemcmp(const wchar_t *, const wchar_t *, size_t);
wchar_t *wmemcpy(wchar_t *restrict, const wchar_t *restrict, size_t);
wchar_t *wmemmove(wchar_t *, const wchar_t *, size_t);
wchar_t *wmemset(wchar_t *, wchar_t, size_t);
int wprintf(const wchar_t *restrict, ...);
int wscanf(const wchar_t *restrict, ...);

#endif
