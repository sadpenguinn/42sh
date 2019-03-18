#include "readline.h"
#include "libft.h"

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

static int	replace_string_by_symbol(t_matrix *matrix, t_uchar c)
{
	t_line		*line;
	t_cursor	point1;
	t_cursor	point2;
	size_t		symbols;
	char		str[sizeof(t_uchar)];

	set_points(&point1, &point2);
	line = matrix->lines[point1.row];
	symbols = count_string_symbols(line->buf, point1.col, point2.col);
	*matrix->cursor = matrix_string_delete(point1, point2);
	while (symbols)
	{
		ft_memset(str, 0, sizeof(t_uchar));
		*matrix->cursor = matrix_string_insert(matrix, *matrix->cursor,
											   str, symbol_to_string(c, str));
		symbols--;
	}
	move_cursor_left(matrix);
	g_shortcuts[SHORTCUT_ARRAY_SIZE - 1] = 0;
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

int			vi_mode_visual_is_normal_mode(t_matrix *matrix, t_uchar c)
{
	g_vi_mode = NORMAL_MODE;
	if (is_normal_mode_basic(matrix, c))
		return (1);
	if (is_normal_mode_advanced(matrix, c))
		return (1);
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'r')
		return (replace_string_by_symbol(matrix, c));
	g_vi_mode = VISUAL_MODE;
	return (0);
}
