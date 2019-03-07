#include "readline.h"
#include "shell.h"

void	history_resize(t_history *history)
{
	history->matrix =
			(t_matrix **)xrealloc(history->matrix,
								  history->size * RATIO * sizeof(t_matrix *),
								  history->size * sizeof(t_matrix *));
	history->size *= RATIO;
}

