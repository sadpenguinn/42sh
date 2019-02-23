#include "readline.h"

int		move_shortcuts(t_uchar c)
{
	int	i;

	i = 0;
	while (i < SHORTCUT_ARRAY_SIZE - 1)
	{
		g_shortcuts[i] = g_shortcuts[i + 1];
		i++;
	}
	g_shortcuts[i] = c;
	return (1);
}

