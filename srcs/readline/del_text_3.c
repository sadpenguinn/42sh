#include "readline.h"

int	del_find_next_char(t_matrix *matrix)
{
	t_cursor	pos;
	size_t		col;

	col = matrix->cursor->col;
	matrix->cursor->col = get_cursor_pos_find_next_char(matrix);
	if (col == matrix->cursor->col)
		return (1);
	pos.col = get_cursor_pos_right(matrix);
	pos.row = matrix->cursor->row;
	matrix->cursor->col = col;
	matrix_string_delete(*matrix->cursor, pos);
	return (1);
}

int	del_find_back_char(t_matrix *matrix)
{
	t_cursor	pos;
	size_t		col;

	col = matrix->cursor->col;
	matrix->cursor->col = get_cursor_pos_find_back_char(matrix);
	if (col == matrix->cursor->col)
		return (1);
	pos.col = matrix->cursor->col;
	pos.row = matrix->cursor->row;
	matrix->cursor->col = col;
	matrix_string_delete(pos, *matrix->cursor);
	return (1);
}

int	del_find_char_usual_order(t_matrix *matrix)
{
	char	c;

	c = g_history->prev_find_option;
	if (c != 'f' && c != 'F')
		return (1);
	if (c == 'f')
		return (del_find_next_char(matrix));
	return (del_find_back_char(matrix));
}

int	del_find_char_reverse_order(t_matrix *matrix)
{
	char	c;

	c = g_history->prev_find_option;
	if (c != 'f' && c != 'F')
		return (1);
	if (c == 'F')
		return (del_find_next_char(matrix));
	return (del_find_back_char(matrix));
}
