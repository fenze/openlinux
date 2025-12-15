#include <libc.h>   // for __unused
#include <string.h> // for strcmp, locale_t, strcoll, strcoll_l
#include <sys/cdefs.h>

int strcoll(const char *s1, const char *s2)
{
	return strcmp(s1, s2);
}

__weak int strcoll_l(const char *s1, const char *s2, locale_t __unused locale)
{
	return strcoll(s1, s2);
}
