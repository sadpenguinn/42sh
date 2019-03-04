#include "readline.h"

int del_string(t_matrix *matrix)
{
	int col;

	col = get_cursor_pos_end(matrix);
	matrix->cursor->col = get_cursor_pos_begin(matrix);
	matrix_string_delete(matrix, matrix->cursor->row, col);
	return (1);
}
