#include "readline.h"
#include <string.h>

void	matrix_string_delete(t_matrix *matrix, int row, int col)
{
	t_line	*line;
	int 	i;
	int 	symbols;

	line = matrix->lines[matrix->cursor->row];
	if (row == matrix->cursor->row)
	{
		i = matrix->cursor->col;
		symbols = 0;
		while (i < col)
		{
			i += 1 + get_utf_offset_right(line->buf[i]);
			symbols++;
		}
		memmove(line->buf + matrix->cursor->col, line->buf + i,
			line->len - i);
		line->len -= i - matrix->cursor->col;
		line->symbols -= symbols;
	}
}