#ifndef __STDIO_H
#define __STDIO_H

#ifndef NULL
#define NULL ((void *)0)
#endif

#define _IOFBF 2
#define _IOLBF 1
#define _IONBF 0

#undef SEEK_SET
#undef SEEK_CUR
#undef SEEK_END
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define BUFSIZ 4096

#define EOF (-1)

typedef struct __FILE FILE;
typedef __builtin_va_list va_list;
typedef __SIZE_TYPE__ size_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;

void clearerr(FILE *);
char *ctermid(char *);
int fclose(FILE *);
void setbuf(FILE *restrict, char *restrict);
int ferror(FILE *);
int fflush(FILE *);
int puts(const char *);
int fputs(const char *restrict, FILE *restrict);
void perror(const char *);
int fputc(int, FILE *);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);
int printf(const char *restrict, ...);
int vfprintf(FILE *restrict, const char *restrict, va_list);
int setvbuf(FILE *restrict, char *restrict, int, size_t);
int putc(int, FILE *);
int putchar(int);
size_t fread(void *restrict, size_t, size_t, FILE *restrict);
int fseek(FILE *, long, int);

#endif
