#include "readline.h"

int	move_cursor_next_word(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_next_word(matrix);
	return (1);
}

int move_cursor_begin_word(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_begin_word(matrix);
	return (1);
}

int move_cursor_end_word(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_end_word(matrix);
	return (1);
}
