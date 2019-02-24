#include "readline.h"

int     readline_mode(t_matrix *matrix, t_uchar c)
{
	char	str[8];

	memset(str, 0, 8);
	if (c == BS)
		return (back_space(matrix));
	if (c == '\t' && g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == CTRL_V)
		return (print_autocomplete(matrix));
	if (c == '\n')
		return (newline_handling(matrix));
	matrix_string_insert(matrix, matrix->cursor,
						 str, symbol_to_string(c, str));
	return (1);
}
