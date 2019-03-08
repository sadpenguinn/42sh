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
		const char *str, size_t size)
{
	if (size == 0)
		return (pos);
	if (line->len + size > line->size)
		line_resize(line, line->len + size + line->size * RATIO, line->size);
	if (pos < line->len)
		ft_memmove(line->buf + pos + size, line->buf + pos,
				line->len - pos);
	ft_memcpy(line->buf + pos, str, size);
	line->len += size;
	line->symbols += count_string_symbols(str, size);
	return (pos + size);
}

t_cursor	matrix_string_insert(t_matrix *matrix,
		t_cursor pos, const char *str, size_t size)
{
	t_line		*line;

	line = matrix->lines[pos.row];
	pos.col = line_string_insert(line, pos.col, str, size);
	return (pos);
}
