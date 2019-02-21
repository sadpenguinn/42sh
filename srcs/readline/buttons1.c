#include "readline.h"

int		back_space(t_matrix *matrix)
{
	if (matrix->cursor->col != 0)
	{
		move_cursor_left(matrix);
		matrix_string_delete(matrix, 1);
	}
	return (print_default(matrix));
}

int		del(t_matrix *matrix)
{
	if (matrix->cursor->col != matrix->lines[matrix->cursor->row]->len)
		matrix_string_delete(matrix, 1);
	return (print_default(matrix));
}

