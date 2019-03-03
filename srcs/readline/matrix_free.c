#include "readline.h"
#include <stdlib.h>

void	matrix_free(t_matrix *matrix)
{
	int i;

	if (matrix == NULL)
		return ;
	free(matrix->cursor);
	i = 0;
	while (i < matrix->len)
		line_free(matrix->lines[i++]);
	free(matrix->lines);
	free(matrix);
}
