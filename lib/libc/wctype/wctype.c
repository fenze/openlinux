#include <libc.h>
#include <wctype.h>
#include <string.h>

wctype_t wctype(const char *property)
{
	int i;
	const char *ptr;
	static const char n[] = "alnum\0"
				"alpha\0"
				"blank\0"
				"cntrl\0"
				"digit\0"
				"graph\0"
				"lower\0"
				"print\0"
				"punct\0"
				"space\0"
				"upper\0"
				"xdigit";

	for (i = 1, ptr = n; *ptr; i++, ptr += strlen(ptr) + 1)
		if (!strcmp(property, ptr))
			return i;

	return 0;
}

weak wctype_t wctype_l(const char *property, locale_t unused locale)
{
	return wctype(property);
}
