#include "readline.h"
#include "libft.h"

void	search_in_history(t_line *line)
{
	int		cur;
	char	*substr;

	cur = g_history->len - 1;
	substr = (char *)xmalloc(sizeof(char) * line->len + 1);
	ft_memcpy(substr, line->buf, line->len);
	while (cur >= 0)
	{
		if (ft_strstr(g_history->matrix[cur]->str_history->buf, substr))
			break;
		cur--;
	}
	if (cur >= 0)
	{
		matrix_del(&g_history->cur_matrix);
		g_history->cur_matrix = matrix_dup(g_history->matrix[cur]);
		g_history->cur_matrix->cursor->row = g_history->cur_matrix->len - 1;
		g_history->cur_matrix->cursor->col =
				g_history->cur_matrix->lines[g_history->cur_matrix->len - 1]->len;
		g_history->cur = cur;
	}
}

int		search_next(t_line *line)
{
	int 	cur;
	char	*substr;

	cur = g_history->cur - 1;
	substr = (char *)xmalloc(sizeof(char) * line->len + 1);
	ft_memcpy(substr, line->buf, line->len);
	while (cur >= 0)
	{
		if (ft_strstr(g_history->matrix[cur]->str_history->buf, substr))
			break;
		cur--;
	}
	if (cur < 0)
	{
		cur = g_history->len - 1;
		while (cur > g_history->cur)
		{
			if (ft_strstr(g_history->matrix[cur]->str_history->buf, substr))
				break;
			cur--;
		}
	}
	if (cur != g_history->cur)
	{
		matrix_del(&g_history->cur_matrix);
		g_history->cur_matrix = matrix_dup(g_history->matrix[cur]);
		g_history->cur_matrix->cursor->row = g_history->cur_matrix->len - 1;
		g_history->cur_matrix->cursor->col =
				g_history->cur_matrix->lines[g_history->cur_matrix->len - 1]->len;
		g_history->cur = cur;
	}
	return (1);
}

int		search_mode(t_matrix *matrix, t_uchar c)
{
	t_line	*line;
	char 	str[8];

	line = g_history->search_line;
	if (c == CTRL_B || c == LEFT || c == CTRL_F || c == RIGHT ||
			c == HOME1 || c == HOME2 || c == END1 || c == END2 ||
			c == CTRL_P || c == CTRL_N || c == UP || c == DOWN ||
			c == DEL || c == '\n' || c == '\t')
	{
		g_search_mode = 0;
		line->len = 0;
		if (c == '\n')
			return (newline_handling(matrix));
		return (1);
	}
	if (c == CTRL_R)
		return (search_next(line));
	ft_memset(str, 0, 8);
	if (c == BS)
		line_string_delete(line, line->len - 1, 1);
	else
		line_string_insert(line, line->len, str, symbol_to_string(c, str));
	search_in_history(line);
	return (1);
}
