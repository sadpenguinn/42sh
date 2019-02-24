#include "readline.h"

int	symbol_to_string(t_uchar c, char *str)
{
	int	i;
	int	n;

	i = 0;
	if (c == '\t')
	{
		while (i < 4)
			str[i++] = ' ';
		return (i);
	}
	n = get_utf_offset_right(*((char *)&c));
	while (i <= n)
	{
		str[i] = ((c >> (i * 8)) & 0xFF);
		i++;
	}
	return (i);
}
