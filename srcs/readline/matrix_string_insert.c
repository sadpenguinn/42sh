/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_string_insert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:57:29 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 18:54:29 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

size_t		line_string_insert(t_line *line, size_t pos,
		const char *buf, size_t size)
{
	if (size == 0)
		return (pos);
	if (line->len + size > line->size)
		line_resize(line, line->len + size + line->size * RATIO, line->size);
	ft_memset(line->buf + line->len, 0, size);
	if (pos < line->len)
		ft_memmove(line->buf + pos + size, line->buf + pos,
				line->len - pos);
	ft_memcpy(line->buf + pos, buf, size);
	line->len += size;
	line->symbols += count_string_symbols(buf, 0, size);
	return (pos + size);
}

t_cursor	matrix_string_insert(t_matrix *matrix,
		t_cursor start, const char *buf, size_t size)
{
	t_line		*line;
	t_cursor	end;

	line = matrix->lines[start.row];
	end.row = start.row;
	end.col = line_string_insert(line, start.col, buf, size);
	if (g_history->redo_undo == 0)
		action_add(start, end, buf, INSERT);
	return (end);
}
