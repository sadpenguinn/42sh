#include "readline.h"

int move_cursor_left(t_matrix *matrix)
{
	if (matrix->cursor->col != 0)
		matrix->cursor->col--;
	return (1);
}

int move_cursor_right(t_matrix *matrix)
{
	if (matrix->cursor->col != matrix->lines[matrix->cursor->row]->len)
		matrix->cursor->col++;
	return (1);
}

int move_cursor_up(t_matrix *matrix)
{
	if (matrix->cursor->row)
	{
		matrix->cursor->row--;
		if (matrix->lines[matrix->cursor->row]->len < matrix->cursor->col)
			matrix->cursor->col = matrix->lines[matrix->cursor->row]->len;
	}
	return (1);
}

int move_cursor_down(t_matrix *matrix)
{
	if (matrix->cursor->row != matrix->len - 1)
	{
		matrix->cursor->row++;
		if (matrix->lines[matrix->cursor->row]->len < matrix->cursor->col)
			matrix->cursor->col = matrix->lines[matrix->cursor->row]->len;
	}
	return (1);
}

