#include "readline.h"

int			modes_handling(t_matrix *matrix, t_uchar c)
{
	add_shortcut(c);
	if (g_mode == READLINE)
		return (readline_mode(matrix, c));
	if (g_mode == VI)
		return (vi_mode(matrix, c));
	return (1);
}

