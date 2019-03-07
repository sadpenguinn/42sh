#include "readline.h"
#include "libft.h"

int insert_mode(t_matrix *matrix, t_uchar c)
{
	char	str[sizeof(t_uchar)];

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
		return (1);
	}
	ft_memset(str, 0, sizeof(t_uchar));
	*matrix->cursor = matrix_string_insert(matrix, *matrix->cursor,
						 str, symbol_to_string(matrix, c, str));
	return (1);
}
