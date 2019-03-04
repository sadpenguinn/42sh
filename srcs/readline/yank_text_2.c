#include "readline.h"

int yank_string(t_matrix *matrix)
{
	int col1;
	int col2;

	col1 = get_cursor_pos_end(matrix);
	col2 = matrix->cursor->col;
	matrix->cursor->col = get_cursor_pos_home(matrix);
	matrix_string_yank(matrix, matrix->cursor->row, col1);
	matrix->cursor->col = col2;
	return (1);
}
