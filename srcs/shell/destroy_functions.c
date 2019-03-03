#include "shell.h"

void	destroy_functions(void)
{
	if (g_func)
	{
		free(g_func);
		g_func = NULL;
	}
}
