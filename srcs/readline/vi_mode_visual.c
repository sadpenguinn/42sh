#include "readline.h"

static int	are_default_vi_mode_visual_shortcuts(t_matrix *matrix, t_uchar c)
{
	if (c == CTRL_B || c == LEFT || c == BS || c == 'h')
		return (move_cursor_left(matrix));
	if (c == CTRL_F || c == RIGHT || c == 'l')
		return (move_cursor_right(matrix));
	if (c == HOME1 || c == HOME2)
		return (move_cursor_home(matrix));
	if (c == END1 || c == END2)
		return (move_cursor_end(matrix));
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
	return (0);
}

static int	is_normal_mode(t_matrix *matrix, t_uchar c)
{
	t_cursor	point1;
	t_cursor	point2;

	g_vi_mode = NORMAL_MODE;
	if (c == CTRL_P)
		return (move_history_prev());
	if (c == CTRL_N)
		return (move_history_next());
	if (c == UP)
		return (move_cursor_up(matrix));
	if (c == DOWN)
		return (move_cursor_down(matrix));
	if (c == 'd' || c == DEL)
	{
		set_points(&point1, &point2);
		*matrix->cursor = matrix_string_delete(point1, point2);
		g_shortcuts[SHORTCUT_ARRAY_SIZE - 1] = 0;
		return (1);
	}
	if (c == 'y')
	{
		set_points(&point1, &point2);
		matrix_string_yank(point1, point2);
		g_shortcuts[SHORTCUT_ARRAY_SIZE - 1] = 0;
		return (1);
	}
	g_vi_mode = VISUAL_MODE;
	return (0);
}

int		visual_mode(t_matrix *matrix, t_uchar c)
{
	if (c == CTRL_R)
		return (1);
	if (c == ESC)
	{
		g_vi_mode = NORMAL_MODE;
		return (1);
	}
	if (are_default_vi_mode_visual_shortcuts(matrix, c))
		return (1);
	if (is_normal_mode(matrix, c))
		return (1);
	return (1);
}
