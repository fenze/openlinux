#ifndef __STDLIB_H
#define __STDLIB_H

#include <stddef.h>
#define __BITS_WAIT_H_
#include <bits/wait.h>

#define __BITS_ERRNO_H_
#include <bits/errno.h>

#ifndef NULL
#define NULL ((void *)0)
#endif

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define MB_CUR_MAX 1

#define RAND_MAX (0x7fffffff)

typedef __SIZE_TYPE__ size_t;

typedef struct {
	int quot;
	int rem;
} div_t;

typedef struct {
	long quot;
	long rem;
} ldiv_t;

typedef struct {
	long long quot;
	long long rem;
} lldiv_t;

_Noreturn void _Exit(int);
long a64l(const char *);
_Noreturn void abort(void);
int abs(int);
void *aligned_alloc(size_t, size_t);
int at_quick_exit(void (*)(void));
int atexit(void (*)(void));
double atof(const char *);
int atoi(const char *);
long atol(const char *);
long long atoll(const char *);
void *bsearch(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));
void *calloc(size_t, size_t);
div_t div(int, int);
double drand48(void);
double erand48(unsigned short[3]);
_Noreturn void exit(int);
void free(void *);
char *getenv(const char *);
int getsubopt(char **restrict, char *const *restrict, char **restrict);
int grantpt(int);
char *initstate(unsigned, char *, size_t);
long jrand48(unsigned short[3]);
char *l64a(long);
long labs(long);
void lcong48(unsigned short[7]);
ldiv_t ldiv(long, long);
long long llabs(long long);
lldiv_t lldiv(long long, long long);
long lrand48(void);
void *malloc(size_t);
int mblen(const char *, size_t);
char *mkdtemp(char *);
int mkostemp(char *, int);
int mkstemp(char *);
long mrand48(void);
long nrand48(unsigned short[3]);
int posix_memalign(void **, size_t, size_t);
int posix_openpt(int);
char *ptsname(int);
int ptsname_r(int, char *, size_t);
int putenv(char *);
void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
_Noreturn void quick_exit(int);
void qsort_r(void *, size_t, size_t, int (*)(const void *, const void *, void *), void *);
int rand(void);
long random(void);
void *realloc(void *, size_t);
void *reallocarray(void *, size_t, size_t);
char *realpath(const char *restrict, char *restrict);
char *secure_getenv(const char *);
unsigned short *seed48(unsigned short[3]);
int setenv(const char *, const char *, int);
void setkey(const char *);
char *setstate(char *);
void srand(unsigned);
void srand48(long);
void srandom(unsigned);
double strtod(const char *restrict, char **restrict);
float strtof(const char *restrict, char **restrict);
long strtol(const char *restrict, char **restrict, int);
long double strtold(const char *restrict, char **restrict);
long long strtoll(const char *restrict, char **restrict, int);
unsigned long strtoul(const char *restrict, char **restrict, int);
unsigned long long strtoull(const char *restrict, char **restrict, int);
int system(const char *);
int unlockpt(int);
int unsetenv(const char *);

#endif
