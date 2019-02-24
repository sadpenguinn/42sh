#include "readline.h"

int	get_lines_offset(int len)
{
	int i;

	if (len == 1 || len == 0)
		return (0);
	i = 0;
	while (len)
	{
		i++;
		len /= 10;
	}
	return (i);
}

int	get_lines_prompt_len(int max)
{
	return (2 + get_lines_offset(max));
}

