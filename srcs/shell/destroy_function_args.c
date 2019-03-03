#include "shell.h"

void	destroy_function_args(void)
{
	if (g_func_args)
	{
		free(g_func_args);
		g_func_args = NULL;
	}
}
