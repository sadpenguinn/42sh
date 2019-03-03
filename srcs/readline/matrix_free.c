#include "readline.h"
#include <stdlib.h>

void	matrix_free(t_matrix *matrix)
{
	int i;

	if (matrix == NULL)
		return ;
	cursor_free(matrix->cursor);
	string_free(matrix->str);
	i = 0;
	while (i < matrix->len)
		line_free(matrix->lines[i++]);
	free(matrix->lines);
	free(matrix);
}
