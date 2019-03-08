#include "readline.h"

int		back_space(t_matrix *matrix)
{
	t_cursor	pos;
	t_line		*line;

	if (matrix->cursor->col == 0 && matrix->cursor->row != 0)
	{
		matrix->cursor->row--;
		matrix->cursor->col = matrix->lines[matrix->cursor->row]->len;
		line = matrix->lines[matrix->cursor->row + 1];
		pos.col = matrix->cursor->col;
		*matrix->cursor = matrix_string_insert(matrix, *matrix->cursor, line->buf, line->len);
		matrix_erase_line(matrix, matrix->cursor->row + 1);
		matrix->cursor->col = pos.col;
	}
	else if (matrix->cursor->col != 0)
	{
		move_cursor_left(matrix);
		line = matrix->lines[matrix->cursor->row];
		pos.col = matrix->cursor->col +
				  1 + get_utf_offset_right(line->buf[matrix->cursor->col]);
		pos.row = matrix->cursor->row;
		matrix_string_delete(*matrix->cursor, pos);
	}
	return (1);
}
