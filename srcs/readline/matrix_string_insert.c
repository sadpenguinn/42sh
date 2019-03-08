/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_string_insert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:57:29 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/03 06:16:14 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

int	line_string_insert(t_line *line, int pos, const char *str, int size)
{
	if (size <= 0)
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

t_cursor	matrix_string_insert(t_matrix *matrix, t_cursor pos, const char *str, int size)
{
	t_line		*line;

	line = matrix->lines[pos.row];
	pos.col = line_string_insert(line, pos.col, str, size);
	return (pos);
}
