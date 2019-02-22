#include "readline.h"
#include <string.h>

void	matrix_string_delete(t_matrix *matrix, int size)
{
	t_line	*line;

	line = matrix->lines[matrix->cursor->row];
	if (line->len == 0)
		return ;
	memmove(line->buf + matrix->cursor->col,
		line->buf + matrix->cursor->col + size,
		line->len - matrix->cursor->col);
	line->len -= size;
}