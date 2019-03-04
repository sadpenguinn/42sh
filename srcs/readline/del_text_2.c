#include "readline.h"

int del_string(t_matrix *matrix)
{
	int col;

	col = get_cursor_pos_end(matrix);
	matrix->cursor->col = get_cursor_pos_begin(matrix);
	matrix_string_delete(matrix, matrix->cursor->row, col);
	return (1);
}

int del_begin_alnum(t_matrix *matrix)
{
	int col;

	col = matrix->cursor->col;
	matrix->cursor->col = get_cursor_pos_begin_alnum(matrix);
	matrix_string_delete(matrix, matrix->cursor->row, col);
	return (1);
}

int del_next_alnum(t_matrix *matrix)
{
	int col;

	col = get_cursor_pos_next_alnum(matrix);
	matrix_string_delete(matrix, matrix->cursor->row, col);
	return (1);
}

int del_end_alnum(t_matrix *matrix)
{
	int col;

	col = get_cursor_pos_end_alnum(matrix);
	matrix_string_delete(matrix, matrix->cursor->row, col);
	return (1);
}
