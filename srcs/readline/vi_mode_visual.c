#include "readline.h"

int		visual_mode(t_matrix *matrix, t_uchar c)
{
	if (c == CTRL_R)
	{
		g_search_mode = 1;
		return (1);
	}
	if (c == ESC)
	{
		g_vi_mode = NORMAL_MODE;
		return (1);
	}
	if (c == LEFT || c == 'h')
		return (move_cursor_left(matrix));
	if (c == RIGHT || c == 'l')
		return (move_cursor_right(matrix));
	return (1);
}
