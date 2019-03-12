#include "shell.h"

void	destroy_aliases(void)
{
	alias_clean(&g_aliases);
}
