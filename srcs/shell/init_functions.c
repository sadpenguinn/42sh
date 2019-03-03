#include "shell.h"
#include "execute.h"

void 	init_functions(void)
{
	g_func = vector_create(sizeof(t_func));
}
