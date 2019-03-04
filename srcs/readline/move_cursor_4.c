#include "readline.h"

int	move_cursor_next_alnum(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_next_alnum(matrix);
	return (1);
}

int move_cursor_begin_alnum(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_begin_alnum(matrix);
	return (1);
}

int move_cursor_end_alnum(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_end_alnum(matrix);
	return (1);
}
