/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bang_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 11:02:52 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/09 11:02:58 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

int	bang_case(t_line *line, size_t pos)
{
	t_string	*substr;

	if (g_history->len == 1)
		return (BANG_ERROR);
	substr = string_dup(g_history->matrix[g_history->len - 2]->str_history);
	line_string_delete(line, pos - 2, 2);
	line_string_insert(line, pos - 2, substr->buf, substr->len);
	string_free(substr);
	return (BANG_REPLACED);
}

int	word_case(t_line *line, size_t pos)
{
	size_t		i;
	char		*substr;
	int			flag;

	i = pos;
	while (i < line->len && line->buf[i] != ' ' && line->buf[i] != ';')
		i++;
	substr = (char *)xmalloc(sizeof(char) * (i - pos + 1));
	ft_memcpy(substr, line->buf + pos, i - pos);
	flag = 0;
	i = g_history->len - 1;
	while (i--)
		if (ft_strncmp(g_history->matrix[i]->str_history->buf,
					substr, i - pos) == 0)
		{
			flag = 1;
			break ;
		}
	free(substr);
	if (flag == 0)
		return (BANG_ERROR);
	line_string_delete(line, pos - 1, i - pos + 1);
	line_string_insert(line, pos - 1, g_history->matrix[i]->str_history->buf,
			g_history->matrix[i]->str_history->len);
	return (BANG_REPLACED);
}

int	minus_case(t_line *line, size_t pos)
{
	size_t		nbr;
	t_string	*substr;
	size_t		len;

	if (pos == line->len)
		return (word_case(line, pos - 1));
	if (!(line->buf[pos] >= '1' && line->buf[pos] <= '9'))
		return (word_case(line, pos - 1));
	nbr = (size_t)ft_atoi(line->buf + pos);
	if (nbr >= g_history->len)
		return (BANG_ERROR);
	len = 0;
	while (pos + len < line->len && line->buf[pos + len] >= '0' &&
			line->buf[pos + len] <= '9')
		len++;
	substr = string_dup(g_history->matrix[g_history->len - 1 - nbr]->
			str_history);
	line_string_delete(line, pos - 2, len + 2);
	line_string_insert(line, pos - 2, substr->buf, substr->len);
	string_free(substr);
	return (BANG_REPLACED);
}

int	plus_case(t_line *line, size_t pos, int plus_flag)
{
	size_t		nbr;
	t_string	*substr;
	size_t		len;

	if (pos == line->len)
		return (word_case(line, pos - 1));
	if (!(line->buf[pos] >= '1' && line->buf[pos] <= '9'))
		return (word_case(line, pos - 1));
	nbr = (size_t)ft_atoi(line->buf + pos);
	if (nbr >= g_history->len)
		return (BANG_ERROR);
	len = 0;
	while (pos + len < line->len && line->buf[pos + len] >= '0' &&
			line->buf[pos + len] <= '9')
		len++;
	substr = string_dup(g_history->matrix[nbr]->str_history);
	line_string_delete(line, pos - 1 - plus_flag, len + 2);
	line_string_insert(line, pos - 1 - plus_flag, substr->buf, substr->len);
	string_free(substr);
	return (BANG_REPLACED);
}
