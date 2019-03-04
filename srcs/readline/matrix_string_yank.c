#include "readline.h"

void	matrix_string_yank(t_matrix *matrix, int row, int col)
{
	t_line		*line;
	t_cursor	cursor;

	cursor.row = matrix->cursor->row;
	cursor.col = matrix->cursor->col;
	if (cursor.row > row || (cursor.row == row && cursor.col > col))
	{
		cursor.row = row;
		cursor.col = col;
		row = matrix->cursor->row;
		col = matrix->cursor->col;
	}
	if (cursor.row == row)
	{
		line = matrix->lines[cursor.row];
		buffer_free();
		buffer_add(line->buf + cursor.col,
				   col - cursor.col);
	}
}
