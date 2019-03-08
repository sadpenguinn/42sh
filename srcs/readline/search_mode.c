/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:25:13 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:25:46 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

void	search_in_history(t_line *line)
{
	int		cur;
	char	*substr;

	substr = (char *)xmalloc(sizeof(char) * line->len + 1);
	ft_memcpy(substr, line->buf, line->len);
	cur = g_history->len;
	while (--cur >= 0)
		if (ft_strstr(g_history->matrix[cur]->str_history->buf, substr))
			break ;
	if (cur >= 0)
		g_history->cur = cur;
	free(substr);
}

int		search_next(t_line *line)
{
	int		cur;
	char	*substr;

	substr = (char *)xmalloc(sizeof(char) * line->len + 1);
	ft_memcpy(substr, line->buf, line->len);
	cur = g_history->cur;
	while (--cur >= 0)
		if (ft_strstr(g_history->matrix[cur]->str_history->buf, substr))
			break ;
	if (cur < 0)
	{
		cur = g_history->len;
		while (--cur > g_history->cur)
			if (ft_strstr(g_history->matrix[cur]->str_history->buf, substr))
				break ;
	}
	if (cur != g_history->cur)
		g_history->cur = cur;
	free(substr);
	return (1);
}

int		search_mode(t_uchar c)
{
	t_line		*line;
	char		str[8];

	line = g_history->search_line;
	if (c == CTRL_B || c == LEFT || c == CTRL_F || c == RIGHT ||
			c == HOME1 || c == HOME2 || c == END1 || c == END2 ||
			c == CTRL_P || c == CTRL_N || c == UP || c == DOWN ||
			c == DEL || c == '\n' || c == '\t')
	{
		g_search_mode = 0;
		line->len = 0;
		move_cursor_end(g_history->matrix[g_history->cur]);
		if (c == '\n')
			return (newline_handling(g_history->matrix[g_history->cur]));
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
