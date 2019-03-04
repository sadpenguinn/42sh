#include "readline.h"

static int	normal_mode_del(t_matrix *matrix, t_uchar c)
{
	if (c == 'B')
		return (del_begin_word(matrix));
	if (c == 'W')
		return (del_next_word(matrix));
	if (c == 'E')
		return (del_end_word(matrix));
	if (c == '$')
		return (del_end(matrix));
	if (c == '^')
		return (del_home(matrix));
	return (1);
}

static int	normal_mode_yank(t_matrix *matrix, t_uchar c)
{
	if (c == 'B')
		return (yank_begin_word(matrix));
	if (c == 'W')
		return (yank_end_word(matrix));
	if (c == 'E')
		return (yank_end_word(matrix));
	if (c == '$')
		return (yank_end(matrix));
	if (c == '^')
		return (yank_home(matrix));
	return (1);
}

static int	is_insert_mode(t_matrix *matrix, t_uchar c)
{
	if (c == 'i')
	{
		g_vi_mode = INSERT_MODE;
		return (1);
	}
	if (c == 'a')
	{
		g_vi_mode = INSERT_MODE;
		return (move_cursor_right(matrix));
	}
	if (c == 'I')
	{
		g_vi_mode = INSERT_MODE;
		return (move_cursor_home(matrix));
	}
	if (c == 'A')
	{
		g_vi_mode = INSERT_MODE;
		return (move_cursor_end(matrix));
	}
	return (0);
}

static int	are_default_normal_mode_shortcuts(t_matrix *matrix, t_uchar c)
{
	if (c == 'W')
		return (move_cursor_next_word(matrix));
	if (c == 'B')
		return (move_cursor_begin_word(matrix));
	if (c == 'E')
		return (move_cursor_end_word(matrix));
	if (c == '$')
		return (move_cursor_end(matrix));
	if (c == '^')
		return (move_cursor_home(matrix));
	if (c == 'h')
		return (move_cursor_left(matrix));
	if (c == 'l')
		return (move_cursor_right(matrix));
	if (c == 'k')
		return (move_cursor_up(matrix));
	if (c == 'j')
		return (move_cursor_down(matrix));
	return (0);
}

int normal_mode(t_matrix *matrix, t_uchar c)
{
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'd')
		return (normal_mode_del(matrix, c));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'y')
		return (normal_mode_yank(matrix, c));
	if (are_default_shortcuts(matrix, c))
		return (1);
	if (is_insert_mode(matrix, c))
		return (1);
	if (are_default_shortcuts(matrix, c))
		return (1);
	if (are_default_normal_mode_shortcuts(matrix, c))
		return (1);
	if (c == 'p')
		paste_after(matrix);
	if (c == 'P')
		paste_before(matrix);
	if (c == '\n')
		return (newline_handling(matrix));
	return (1);
}
