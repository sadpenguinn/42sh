#include "readline.h"
#include "shell.h"

void	action_free(t_action *action)
{
	if (action == NULL)
		return ;
	free(action->buf);
	free(action);
}
