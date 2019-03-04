#include "readline.h"

int del_begin_word(t_matrix *matrix)
{
	int col;

	col = matrix->cursor->col;
	matrix->cursor->col = get_cursor_pos_begin_word(matrix);
	matrix_string_delete(matrix, matrix->cursor->row, col);
	return (1);
}

int del_next_word(t_matrix *matrix)
{
	int col;

	col = get_cursor_pos_next_word(matrix);
	matrix_string_delete(matrix, matrix->cursor->row, col);
	return (1);
}

int del_end_word(t_matrix *matrix)
{
	int col;

	col = get_cursor_pos_end_word(matrix);
	matrix_string_delete(matrix, matrix->cursor->row, col);
	return (1);
}

int del_end(t_matrix *matrix)
{
	int col;

	col = get_cursor_pos_end(matrix);
	matrix_string_delete(matrix, matrix->cursor->row, col);
	return (1);
}

int del_home(t_matrix *matrix)
{
	int col;

	col = matrix->cursor->col;
	matrix->cursor->col = get_cursor_pos_home(matrix);
	matrix_string_delete(matrix, matrix->cursor->row, col);
	return (1);
}
