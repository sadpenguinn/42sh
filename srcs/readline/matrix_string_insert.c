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

static int	line_string_insert(t_line *line, const char *str,
	t_cursor *cursor, int limit)
{
	int	size;
	int	symbols;

	if (limit == 0)
		return (0);
	size = 0;
	symbols = 0;
	while ((str[size] != '\n' || str[size]) && size < limit)
	{
		size += 1 + get_utf_offset_right(str[size]);
		symbols++;
	}
	if (line->len + size > line->size)
		line_resize(line, line->len + size + line->size * RATIO, line->size);
	if (cursor->col < line->len)
		memmove(line->buf + cursor->col + size, line->buf + cursor->col,
				line->len - cursor->col);
	memcpy(line->buf + cursor->col, str, size);
	cursor->col += size;
	line->len += size;
	line->symbols += symbols;
	if (str[size] == '\n' && size < limit)
		return (size + 1);
	return (size);
}

void		matrix_string_insert(t_matrix *matrix,
		t_cursor *pos, const char *str, int size)
{
	int			i;
	t_line		*line;
	t_cursor	cursor;
	int			len;

	if (pos->col == 0 && str[size - 1] == '\n')
		matrix_create_line(matrix, pos->row);
	line = matrix->lines[pos->row];
	i = line_string_insert(line, str, matrix->cursor, size);
	if (i == size)
		return ;
	cursor.row = pos->row;
	cursor.col = pos->col;
	len = line->len;
	line->len = cursor.col;
	line->symbols = count_string_symbols(line->buf, line->len);
	while (i < size)
	{
		matrix_create_line(matrix, pos->row);
		line = matrix->lines[pos->row];
		i += line_string_insert(line, str + i, matrix->cursor, size);
	}
	line_string_insert(line, matrix->lines[cursor.row]->buf + cursor.col,
		matrix->cursor, len - cursor.col);
}
