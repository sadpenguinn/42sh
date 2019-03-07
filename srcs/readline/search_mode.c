#include "readline.h"
#include "libft.h"

int		search_mode(t_matrix *matrix, t_uchar c)
{
	t_line	*line;
	char 	str[8];

	if (c == LEFT || c == RIGHT || c == UP || c == DOWN
	|| c == '\n')
	{
		g_search_mode = 0;
		if (c == '\n')
			return (newline_handling(matrix));
	}
	line = g_history->search_line;
	if (c == BS)
	{
		if (line->len != 0)
			line_string_delete(line, line->len - 1, 1);
	}
	else
	{
		ft_memset(str, 0, 8);
		line_string_insert(line, line->len, str, symbol_to_string(c, str));
	}
	return (1);
}
