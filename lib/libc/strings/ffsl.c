int ffsl(long i)
{
	int pos;
	unsigned long u;

	if (i == 0) {
		return 0;
	}

	pos = 1;
	u = (unsigned long)i;
	while ((u & 1UL) == 0UL) {
		u >>= 1;
		pos++;
	}

	return pos;
}
