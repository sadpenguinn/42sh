#include "readline.h"

int del_begin_word(t_matrix *matrix)
{
	t_cursor	pos;
	int col;

	col = matrix->cursor->col;
	matrix->cursor->col = get_cursor_pos_begin_word(matrix);
	pos.col = get_cursor_pos_left(matrix);
	pos.row = matrix->cursor->row;
	matrix->cursor->col	= col;
	matrix_string_delete(*matrix->cursor, pos);
	return (1);
}

int del_next_word(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_next_word(matrix);
	pos.row = matrix->cursor->row;
	matrix_string_delete(*matrix->cursor, pos);
	return (1);
}

int del_end_word(t_matrix *matrix)
{
	t_cursor	pos;
	int col;

	col = matrix->cursor->col;
	matrix->cursor->col = get_cursor_pos_end_word(matrix);
	pos.col = get_cursor_pos_right(matrix);
	pos.row = matrix->cursor->row;
	matrix->cursor->col	= col;
	matrix_string_delete(*matrix->cursor, pos);
	return (1);
}

int del_end(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_end(matrix);
	pos.row = matrix->cursor->row;
	matrix_string_delete(*matrix->cursor, pos);
	return (1);
}

int del_home(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = matrix->cursor->col;
	pos.row = matrix->cursor->row;
	matrix->cursor->col = get_cursor_pos_home(matrix);
	matrix_string_delete(*matrix->cursor, pos);
	return (1);
}
