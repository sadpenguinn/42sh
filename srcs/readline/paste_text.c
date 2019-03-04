#include "readline.h"

void	paste_before(t_matrix *matrix)
{
	matrix_string_insert(matrix, matrix->cursor, get_buffer_content(), get_buffer_len());
	move_cursor_left(matrix);
}

void	paste_after(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_right(matrix);
	matrix_string_insert(matrix, matrix->cursor, get_buffer_content(), get_buffer_len());
	move_cursor_left(matrix);
}
