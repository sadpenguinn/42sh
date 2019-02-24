#include "readline.h"

int count_string_symbols(char *buf, int col)
{
	int	i;
	int	symbols;

	i = 0;
	symbols = 0;
	while (i < col)
	{
		i += 1 + get_utf_offset_right(buf[i]);
		symbols++;
	}
	return (symbols);
}

int	count_string_cols(char *buf, int symbols)
{
	int col;

	col = 0;
	while (symbols)
	{
		col += 1 + get_utf_offset_right(buf[col]);
		symbols--;
	}
	return (col);
}
