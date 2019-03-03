#include "readline.h"
#include "libshell.h"

int 	matrix_cmp(t_matrix *matrix1, t_matrix *matrix2)
{
	int	i;

	if (matrix1->len != matrix2->len)
		return (1);
	i = 0;
	while (i < matrix1->len)
	{
		if (matrix1->lines[i]->len != matrix2->lines[i]->len)
			return (1);
		if (ft_strcmp(matrix1->lines[i]->buf, matrix2->lines[i]->buf) != 0)
			return (1);
		i++;
	}
	return (0);
}
