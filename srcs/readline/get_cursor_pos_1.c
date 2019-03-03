#include "readline.h"

int	get_cursor_pos_home(t_matrix *matrix)
{
	(void)matrix;
	return (0);
}

int	get_cursor_pos_end(t_matrix *matrix)
{
	return (matrix->lines[matrix->cursor->row]->len);
}

int	get_cursor_pos_left(t_matrix *matrix)
{
	if (matrix->cursor->col)
		return (matrix->cursor->col - (1 +
				get_utf_offset_left(matrix->lines[matrix->cursor->row]->buf,
									matrix->cursor->col - 1)));
	return (0);
}

int	get_cursor_pos_right(t_matrix *matrix)
{
	if (matrix->cursor->col != matrix->lines[matrix->cursor->row]->len)
		return (matrix->cursor->col + 1 +
				get_utf_offset_right(*(matrix->lines[matrix->cursor->row]->buf
									   + matrix->cursor->col)));
	return (matrix->lines[matrix->cursor->row]->len);
}
