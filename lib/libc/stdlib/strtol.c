#include <ctype.h>
#include <stddef.h>
#include <limits.h>

unsigned long long __intscan(const char *s, unsigned base,
			     unsigned long long lim, int *error)
{
	unsigned long long res = 0;
	const char *p = s;
	int digit;

	if (base < 2 || base > 36) {
		if (error)
			*error = 1;
		return 0;
	}

	while (*p && isspace(*p))
		p++;

	while (*p) {
		char c = *p;
		if (isdigit(c))
			digit = c - '0';
		else if (isalpha(c))
			digit = toupper(c) - 'A' + 10;
		else
			break;

		if (digit >= (int)base)
			break;

		if (res > (lim - digit) / base) {
			if (error)
				*error = 1;
			return lim;
		}

		res = res * base + digit;
		p++;
	}

	if (error)
		*error = 0;

	return res;
}

long strtol(const char *restrict nptr, char **restrict endptr, int base)
{
	return __intscan(nptr, base, 0UL + LONG_MIN, NULL);
}
