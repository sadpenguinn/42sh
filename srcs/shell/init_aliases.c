#include "shell.h"

void	init_aliases(void)
{
	g_aliases = alias_init(INITIAL_ALIASES_SIZE);
}
