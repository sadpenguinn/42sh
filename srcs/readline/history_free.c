#include "readline.h"
#include <stdlib.h>

void	history_free(t_history *history)
{
	int	i;

	if (history == NULL)
		return ;
	matrix_free(history->tmp);
	i = 0;
	while (i < history->len)
		matrix_free(history->matrix[i++]);
	free(history->matrix);
	free(history);
}