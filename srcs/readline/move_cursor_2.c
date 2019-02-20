#include "readline.h"

int move_cursor_home(t_matrix *matrix)
{
	matrix->cursor->col = 0;
	return (1);
}

int move_cursor_end(t_matrix *matrix)
{
	matrix->cursor->col = matrix->lines[matrix->cursor->row]->len;
	return (1);
}
