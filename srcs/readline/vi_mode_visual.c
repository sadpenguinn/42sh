#include "readline.h"
#include "libft.h"

static int	are_default_vi_mode_visual_shortcuts(t_matrix *matrix, t_uchar c)
{
	if (c == CTRL_B || c == LEFT || c == BS || c == 'h')
		return (move_cursor_left(matrix));
	if (c == CTRL_F || c == RIGHT || c == 'l')
		return (move_cursor_right(matrix));
	if (c == HOME1 || c == HOME2 || c == '0' || c == '|')
		return (move_cursor_home(matrix));
	if (c == END1 || c == END2 || c == '$')
		return (move_cursor_end(matrix));
	if (c == '^')
		return (move_cursor_begin(matrix));
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

static int	is_find_char(t_matrix *matrix, t_uchar c)
{
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'f')
	{
		g_history->find_char = (char)c;
		g_history->prev_find_option = 'f';
		return (move_cursor_next_char(matrix));
	}
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'F')
	{
		g_history->find_char = (char)c;
		g_history->prev_find_option = 'F';
		return (move_cursor_back_char(matrix));
	}
	if (c == ';')
		return (move_cursor_find_char_reverse_order(matrix));
	if (c == ',')
		return (move_cursor_find_char_usual_order(matrix));
	return (0);
}

static int	change_low_up_case(t_matrix *matrix, t_uchar c)
{
	t_cursor	point1;
	t_cursor	point2;
	size_t		col;
	t_line		*line;

	set_points(&point1, &point2);
	line = matrix->lines[point1.row];
	col = point1.col;
	if (c == 'u')
	{
		while (col < point2.col)
		{
			line->buf[col] = (char)ft_tolower(line->buf[col]);
			col++;
		}
	}
	else
	{
		while (col < point2.col)
		{
			line->buf[col] = (char)ft_toupper(line->buf[col]);
			col++;
		}
	}
	return (1);
}

static int	is_normal_mode_advanced(t_matrix *matrix, t_uchar c)
{
	t_cursor	point1;
	t_cursor	point2;
	t_string	*str;

	set_points(&point1, &point2);
	if (c == 'd' || c == DEL || c == 'x')
	{
		*matrix->cursor = matrix_string_delete(point1, point2);
		g_shortcuts[SHORTCUT_ARRAY_SIZE - 1] = 0;
		return (1);
	}
	if (c == 'p' || c == 'P')
	{
		str = string_init();
		string_fill(str, g_history->buffer->buf, g_history->buffer->len);
		*matrix->cursor = matrix_string_delete(point1, point2);
		buffer_add(str->buf, str->len);
		string_free(str);
		paste_before(matrix);
		return (1);
	}
	if (c == 'u' || c == 'U')
		return (change_low_up_case(matrix, c));
	return (0);
}

static int	is_normal_mode_basic(t_matrix *matrix, t_uchar c)
{
	t_cursor	point1;
	t_cursor	point2;

	if (c == CTRL_P)
		return (move_history_prev());
	if (c == CTRL_N)
		return (move_history_next());
	if (c == UP || c == 'k')
		return (move_cursor_up(matrix));
	if (c == DOWN || c == 'j')
		return (move_cursor_down(matrix));
	if (c == 'X' || c == 'D')
		return (del_string(matrix));
	if (c == 'Y')
		return (yank_string(matrix));
	if (c == 'y')
	{
		set_points(&point1, &point2);
		matrix_string_yank(point1, point2);
		g_shortcuts[SHORTCUT_ARRAY_SIZE - 1] = 0;
		return (1);
	}
	return (0);
}

int			is_normal_mode(t_matrix *matrix, t_uchar c)
{
	g_vi_mode = NORMAL_MODE;
	if (is_normal_mode_basic(matrix, c))
		return (1);
	if (is_normal_mode_advanced(matrix, c))
		return (1);
	g_vi_mode = VISUAL_MODE;
	return (0);
}

static int	is_insert_mode(t_matrix *matrix, t_uchar c)
{
	t_cursor	point1;
	t_cursor	point2;

	g_vi_mode = INSERT_MODE;
	if (c == 'c')
	{
		set_points(&point1, &point2);
		*matrix->cursor = matrix_string_delete(point1, point2);
		return (1);
	}
	if (c == 'I')
		return (move_cursor_home(matrix));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'c')
		return (vi_mode_normal_del(matrix, c));
	if (c == 'A')
		return (1);
	if (c == 's')
		return (del_symbol(matrix));
	if (c == 'S' || c == 'R' || c == 'C')
		return (del_string(matrix));
	g_vi_mode = VISUAL_MODE;
	return (0);
}

int		vi_mode_visual(t_matrix *matrix, t_uchar c)
{
	if (c == ESC)
	{
		g_vi_mode = NORMAL_MODE;
		return (1);
	}
	if (is_find_char(matrix, c))
		return (1);
	if (are_default_vi_mode_visual_shortcuts(matrix, c))
		return (1);
	if (is_normal_mode(matrix, c))
		return (1);
	if (is_insert_mode(matrix, c))
		return (1);
	return (1);
}
/*
 ** visual : r
 */
