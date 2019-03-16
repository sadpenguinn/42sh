#include "readline.h"
#include "shell.h"

void	modification_free(t_modification *modif)
{
	if (modif == NULL)
		return ;
	while (modif->len)
	{
		action_free(modif->actions[modif->len - 1]);
		modif->len--;
	}
	free(modif->actions);
	free(modif);
}
