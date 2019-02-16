int is_utf(char c)
{
	if ((c >> 7) & 1)
		return (1);
	return (0);
}

int is_utf_prefix(char c)
{
	if (((c >> 7) & 1) && (((c >> 6) & 1)))
		return (1);
	return (0);
}

int is_utf_suffix(char c)
{
	if (((c >> 7) & 1) && (((c >> 6) & 1) == 0))
		return (1);
	return (0);
}
