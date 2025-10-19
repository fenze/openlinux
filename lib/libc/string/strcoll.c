#include <libc.h>
#include <string.h>
#include <locale.h>

int strcoll(const char *s1, const char *s2)
{
	return strcmp(s1, s2);
}

weak int strcoll_l(const char *s1, const char *s2, locale_t unused locale)
{
	return strcoll(s1, s2);
}
