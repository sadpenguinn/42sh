#include "readline.h"
#include <unistd.h>

int newline_handling(t_matrix *matrix)
{
	int		prev_col;
	int		prev_row;
	t_line	*line;

	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] != '\\')
		return (0);
	prev_col = matrix->cursor->col;
	prev_row = matrix->cursor->row;
	line = matrix->lines[prev_row];
	matrix_create_line(matrix, matrix->cursor->row + 1);
	if (prev_col != line->len)
	{
		matrix_string_insert(matrix, matrix->cursor,
							 line->buf + prev_col, line->len - prev_col);
		matrix->cursor->col = 0;
	}
	line->len = prev_col - 1;
	line->symbols = count_string_symbols(line->buf, line->len);
	return (1);
}
