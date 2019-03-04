#include "readline.h"
#include <stdio.h>
#include "libft.h"

int insert_mode(t_matrix *matrix, t_uchar c)
{
	char	str[sizeof(t_uchar)];

	ft_memset(str, 0, sizeof(t_uchar));
	if (are_default_shortcuts(matrix, c))
		return (1);
	if (c == BS)
		return (back_space(matrix));
	if (c == '\t' && g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] != CTRL_V)
		return (print_autocomplete(matrix));
	if (c == '\n')
		return (newline_handling(matrix));
	if (c == ESC)
	{
		g_vi_mode = NORMAL_MODE;
		return (move_cursor_left(matrix));
	}
	matrix_string_insert(matrix, matrix->cursor,
						 str, symbol_to_string(matrix, c, str));
	return (1);
}

int	vi_mode(t_matrix *matrix, t_uchar c)
{
	if (g_vi_mode == INSERT_MODE)
		return (insert_mode(matrix, c));
	if (g_vi_mode == NORMAL_MODE)
		return (normal_mode(matrix, c));
	return (1);
}
