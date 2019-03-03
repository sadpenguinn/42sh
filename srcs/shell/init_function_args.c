#include "shell.h"

void 	init_function_args(void)
{
	g_func_args = vector_create(sizeof(char *));
}
