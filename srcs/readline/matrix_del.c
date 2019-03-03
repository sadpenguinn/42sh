#include "readline.h"
#include <stdlib.h>

void	matrix_del(t_matrix **matrix)
{
	if (matrix == NULL)
		return ;
	matrix_free(*matrix);
	*matrix = NULL;
}
