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
	if (c == 'W')
		return (move_cursor_next_word(matrix));
	if (c == 'B')
		return (move_cursor_begin_word(matrix));
	if (c == 'E')
		return (move_cursor_end_word(matrix));
	if (c == 'w')
		return (move_cursor_next_alnum(matrix));
	if (c == 'b')
		return (move_cursor_begin_alnum(matrix));
	if (c == 'e')
		return (move_cursor_end_alnum(matrix));
	return (1);
}
