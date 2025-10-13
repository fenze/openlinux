char *strcat(char *restrict s1, const char *restrict s2)
{
	char *d = s1;

	while (*d)
		d++;

	while (*s2)
		*d++ = *s2++;

	*d = '\0';

	return s1;
}
