#ifndef __MONETARY_H
#define __MONETARY_H

typedef struct __locale_t *locale_t;
typedef __SIZE_TYPE__ size_t;
typedef __INT64_TYPE__ ssize_t;

ssize_t strfmon(char *restrict, size_t, const char *restrict, ...);
ssize_t strfmon_l(char *restrict, size_t, locale_t, const char *restrict, ...);

#endif
