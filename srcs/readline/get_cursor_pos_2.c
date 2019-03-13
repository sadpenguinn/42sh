/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cursor_pos_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:56:53 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 12:57:08 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

size_t	get_cursor_pos_next_word(t_matrix *matrix)
{
	size_t	col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	while (col < line->len && line->buf[col] != ' ')
		col += 1 + get_utf_offset_right(line->buf[col]);
	while (col < line->len && line->buf[col] == ' ')
		col += 1 + get_utf_offset_right(line->buf[col]);
	return (col);
}

size_t	get_cursor_pos_begin_word(t_matrix *matrix)
{
	size_t	col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	if (col && line->buf[col] != ' ')
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	while (col && line->buf[col] == ' ')
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	while (col && line->buf[col] != ' ')
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	if (line->buf[col] == ' ')
		col += 1 + get_utf_offset_right(line->buf[col]);
	return (col);
}

size_t	get_cursor_pos_end_word(t_matrix *matrix)
{
	size_t	col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	if (col < line->len && line->buf[col] != ' ')
		col += 1 + get_utf_offset_right(line->buf[col]);
	while (col < line->len - 1 && line->buf[col] == ' ')
		col += 1 + get_utf_offset_right(line->buf[col]);
	while (col < line->len - 1 && line->buf[col] != ' ')
		col += 1 + get_utf_offset_right(line->buf[col]);
	if (col < line->len && line->buf[col] == ' ')
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	return (col);
}

size_t	get_cursor_pos_back_char(t_matrix *matrix)
{
	size_t	col;
	t_line	*line;
	char	c;

	c = g_history->find_char;
	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	if (col && line->buf[col] == c)
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	while (col && line->buf[col] != c)
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	if (col == 0 && line->buf[col] != c)
		return (matrix->cursor->col);
	return (col);
}

size_t	get_cursor_pos_next_char(t_matrix *matrix)
{
	size_t	col;
	t_line	*line;
	char	c;

	c = g_history->find_char;
	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	if (col < line->len && line->buf[col] == c)
		col += 1 + get_utf_offset_right(line->buf[col]);
	while (col < line->len && line->buf[col] != c)
		col += 1 + get_utf_offset_right(line->buf[col]);
	if (col == line->len)
		return (matrix->cursor->col);
	return (col);
}
