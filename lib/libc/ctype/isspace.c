int isspace(int c)
{
	return c == ' ' || (unsigned)c - '\t' < 5;
}
