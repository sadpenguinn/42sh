#include "readline.h"
#include <stdlib.h>

void	history_del(t_history **history)
{
	if (history == NULL)
		return ;
	history_free(*history);
	*history = NULL;
}