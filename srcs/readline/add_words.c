#include "readline.h"
#include "libft.h"

void			set_points(t_cursor *point1, t_cursor *point2)
{
	t_matrix	*matrix;

	matrix = g_history->matrix[g_history->cur];
	(*point1).row = matrix->cursor->row;
	(*point2).row = (*point1).row;
	if (matrix->cursor->col > matrix->point.col)
	{
		(*point1).col = matrix->point.col;
		(*point2).col = get_cursor_pos_right(matrix);
	}
	else
	{
		(*point1).col = matrix->cursor->col;
		matrix->cursor->col = matrix->point.col;
		(*point2).col = get_cursor_pos_right(matrix);
		matrix->cursor->col = (*point1).col;
	}
}

static int		count_spaces(char c)
{
	if (c == ' ')
		return (1);
	return (TAB_LEN);
}

static void		add_spaces_to_array(size_t n)
{
	while (n)
	{
		array_add(" ", 1);
		n--;
	}
}

size_t			add_spaces(t_line *line, size_t pos, size_t end, size_t row)
{
	t_cursor	point1;
	t_cursor	point2;
	size_t		cnt;

	set_points(&point1, &point2);
	cnt = 0;
	while (pos < end && ft_is_space_tab(line->buf[pos]) &&
		   point1.col != pos && point2.col != pos)
		cnt += count_spaces(line->buf[pos++]);
	add_spaces_to_array(cnt);
	cnt = 0;
	if (point1.row == row && g_vi_mode == VISUAL_MODE && pos == point1.col)
		array_add(BG_COLOR_RED, ft_strlen(BG_COLOR_RED));
	while (pos < end && ft_is_space_tab(line->buf[pos]) && point2.col != pos)
		cnt += count_spaces(line->buf[pos++]);
	add_spaces_to_array(cnt);
	cnt = 0;
	if (point2.row == row && g_vi_mode == VISUAL_MODE && pos == point2.col)
		array_add(BG_DEFAULT_COLOR, ft_strlen(BG_DEFAULT_COLOR));
	while (pos < end && ft_is_space_tab(line->buf[pos]))
		cnt += count_spaces(line->buf[pos++]);
	add_spaces_to_array(cnt);
	return (pos);
}

size_t			add_non_spaces(t_line *line, size_t start, size_t end,
								size_t row)
{
	size_t		pos;
	t_cursor	point1;
	t_cursor	point2;

	set_points(&point1, &point2);
	pos = start;
	while (pos < end && !ft_is_space_tab(line->buf[pos]) &&
		   point1.col != pos && point2.col != pos)
		pos++;
	array_add(line->buf + start, pos - start);
	start = pos;
	if (point1.row == row && g_vi_mode == VISUAL_MODE && pos == point1.col)
		array_add(BG_COLOR_RED, ft_strlen(BG_COLOR_RED));
	while (pos < end && !ft_is_space_tab(line->buf[pos]) && point2.col != pos)
		pos++;
	array_add(line->buf + start, pos - start);
	start = pos;
	if (point2.row == row && g_vi_mode == VISUAL_MODE && pos == point2.col)
		array_add(BG_DEFAULT_COLOR, ft_strlen(BG_DEFAULT_COLOR));
	while (pos < end && !ft_is_space_tab(line->buf[pos]))
		pos++;
	array_add(line->buf + start, pos - start);
	return (pos);
}
