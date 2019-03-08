#include "readline.h"

int			modes_handling(t_uchar c)
{
	t_matrix	*matrix;

	matrix = g_history->matrix[g_history->cur];
	add_shortcut(c);
	if (g_search_mode)
		return (search_mode(c));
	if (g_mode == READLINE)
		return (readline_mode(c));
	if (g_mode == VI)
		return (vi_mode(c));
	return (1);
}

