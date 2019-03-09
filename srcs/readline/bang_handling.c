/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bang_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 11:00:22 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/09 11:03:51 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

static int	replace_bang(t_line *line, size_t pos)
{
	if (pos == line->len || line->buf[pos] == ' ')
		return (NO_BANGS);
	if (line->buf[pos] == '-')
		return (minus_case(line, pos + 1));
	if (line->buf[pos] == '!')
		return (bang_case(line, pos + 1));
	if (line->buf[pos] == '+')
		return (plus_case(line, pos + 1, 1));
	if (line->buf[pos] >= '1' && line->buf[pos] <= '9')
		return (plus_case(line, pos, 0));
	return (word_case(line, pos));
}

static int	check_bang_line(t_line *line)
{
	int		backslash;
	size_t	i;
	int		ret;
	int		flag;

	backslash = 0;
	i = 0;
	flag = 0;
	while (i < line->len)
	{
		if (line->buf[i] == '!' && backslash == 0)
		{
			ret = replace_bang(line, i + 1);
			if (ret == BANG_ERROR)
				return (BANG_ERROR);
			if (ret == BANG_REPLACED)
				flag = 1;
		}
		set_backslash(line->buf, i, &backslash);
		i++;
	}
	if (flag)
		return (BANG_REPLACED);
	return (NO_BANGS);
}

int			bang_handling(t_matrix *matrix)
{
	size_t	i;
	int		flag;
	int		ret;

	i = 0;
	flag = 0;
	while (i < matrix->len)
	{
		ret = check_bang_line(matrix->lines[i]);
		if (ret == BANG_REPLACED)
			flag = 1;
		if (ret == BANG_ERROR)
		{
			g_history->is_replace = 1;
			return (BANG_ERROR);
		}
		i++;
	}
	if (flag)
	{
		matrix->cursor->row = matrix->len - 1;
		matrix->cursor->col = matrix->lines[matrix->len - 1]->len;
		return (BANG_REPLACED);
	}
	return (NO_BANGS);
}
