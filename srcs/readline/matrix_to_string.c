#include "readline.h"
#include "array.h"

char *matrix_to_string(t_matrix *matrix)
{
	int	i;

	i = 0;
	while (i < matrix->len - 1)
	{
		array_add(matrix->lines[i]->buf, matrix->lines[i]->len);
		array_add("\n", 1);
		i++;
	}
	array_add(matrix->lines[i]->buf, matrix->lines[i]->len);
	return (array_to_string());
}

