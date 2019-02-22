#include "readline.h"

int		back_space(t_matrix *matrix)
{
	int		col;
	t_line	*line;

	if (matrix->cursor->col == 0 && matrix->cursor->row != 0)
	{
		line = matrix->lines[matrix->cursor->row];
		matrix->cursor->col = matrix->lines[--matrix->cursor->row]->len;
		col = matrix->cursor->col;
		matrix_string_insert(matrix, line->buf, line->len);
		matrix_erase_line(matrix, matrix->cursor->row + 1);
		matrix->cursor->col = col;
	}
	else if (matrix->cursor->col != 0)
	{
		move_cursor_left(matrix);
		matrix_string_delete(matrix, 1);
	}
	return (print_default(matrix));
}

int		del(t_matrix *matrix)
{
	int		col;
	t_line	*line;

	if (matrix->cursor->col == matrix->lines[matrix->cursor->row]->len &&
		matrix->cursor->row != matrix->len - 1)
	{
		line = matrix->lines[matrix->cursor->row + 1];
		col = matrix->cursor->col;
		matrix_string_insert(matrix, line->buf, line->len);
		matrix_erase_line(matrix, matrix->cursor->row + 1);
		matrix->cursor->col = col;
	} else if (matrix->cursor->col != matrix->lines[matrix->cursor->row]->len)
		matrix_string_delete(matrix, 1);
	return (print_default(matrix));
}
