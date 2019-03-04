#include "readline.h"
#include "libft.h"

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
	if (c == '|' || c == '0')
		return (del_home(matrix));
	if (c == 'd')
	{
		g_shortcuts[SHORTCUT_ARRAY_SIZE - 1] = 0;
		return (del_string(matrix));
	}
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
	if (c == '|' || c == '0')
		return (yank_home(matrix));
	if (c == 'y')
	{
		g_shortcuts[SHORTCUT_ARRAY_SIZE - 1] = 0;
		return (yank_string(matrix));
	}
	return (1);
}

static int	is_insert_mode(t_matrix *matrix, t_uchar c)
{
	g_vi_mode = INSERT_MODE;
	if (c == 'i')
		return (1);
	if (c == 'I')
		return (move_cursor_home(matrix));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'c')
		return (normal_mode_del(matrix, c));
	if (c == 'C')
		return (del_end(matrix));
	if (c == 'a')
		return (move_cursor_right(matrix));
	if (c == 'A')
		return (move_cursor_end(matrix));
	if (c == 's')
		return (del(matrix));
	if (c == 'S')
		return (del_string(matrix));
	g_vi_mode = NORMAL_MODE;
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
	if (c == '|' || c == '0')
		return (move_cursor_home(matrix));
	if (c == '^')
		return (move_cursor_begin(matrix));
	if (c == 'h')
		return (move_cursor_left(matrix));
	if (c == 'l')
		return (move_cursor_right(matrix));
	if (c == 'k')
		return (move_cursor_up(matrix));
	if (c == 'j')
		return (move_cursor_down(matrix));
	if (c == 'x')
		return (del(matrix));
	if (c == 'X')
		return (back_space(matrix));
	if (c == 'D')
		return (del_end(matrix));
	if (c == 'Y')
		return (yank_string(matrix));
	if (c == BS)
		return (move_cursor_left(matrix));
	if (c == 'p')
		paste_after(matrix);
	if (c == 'P')
		paste_before(matrix);
	return (0);
}

static int	replace_symbol(t_matrix *matrix, t_uchar c)
{
	char	str[sizeof(t_uchar)];

	if (c == LEFT || c == RIGHT ||
		c == DOWN || c == UP ||
		c == HOME1 || c == HOME2 ||
		c == END1 || c == END2 ||
		c == DEL || c == BS)
		return (1);
	del(matrix);
	ft_memset(str, 0, sizeof(t_uchar));
	matrix_string_insert(matrix, matrix->cursor,
						 str, symbol_to_string(matrix, c, str));
	matrix->cursor->col = get_cursor_pos_left(matrix);
	g_shortcuts[SHORTCUT_ARRAY_SIZE - 1] = 0;
	return (1);
}

int normal_mode(t_matrix *matrix, t_uchar c)
{
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'd')
		return (normal_mode_del(matrix, c));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'y')
		return (normal_mode_yank(matrix, c));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'r')
		return (replace_symbol(matrix, c));
	if (is_insert_mode(matrix, c))
		return (1);
	if (are_default_shortcuts(matrix, c))
		return (1);
	if (are_default_normal_mode_shortcuts(matrix, c))
		return (1);
	if (c == '\n')
		return (newline_handling(matrix));
	if (c == 'R')
		g_vi_mode = REPLACE_MODE;
	return (1);
}
