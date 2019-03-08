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

int	get_cursor_pos_next_word(t_matrix *matrix)
{
	int		col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	while (line->buf[col] != ' ' && col < line->len)
		col += 1 + get_utf_offset_right(line->buf[col]);
	while (line->buf[col] == ' ' && col < line->len)
		col += 1 + get_utf_offset_right(line->buf[col]);
	return (col);
}

int	get_cursor_pos_begin_word(t_matrix *matrix)
{
	int		col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	if (line->buf[col] != ' ' && col)
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	while (line->buf[col] == ' ' && col)
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	while (line->buf[col] != ' ' && col)
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	if (line->buf[col] == ' ')
		col += 1 + get_utf_offset_right(line->buf[col]);
	return (col);
}

int	get_cursor_pos_end_word(t_matrix *matrix)
{
	int		col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	if (line->buf[col] != ' ' && col < line->len)
		col += 1 + get_utf_offset_right(line->buf[col]);
	while (line->buf[col] == ' ' && col < line->len - 1)
		col += 1 + get_utf_offset_right(line->buf[col]);
	while (line->buf[col] != ' ' && col < line->len - 1)
		col += 1 + get_utf_offset_right(line->buf[col]);
	if (col < line->len && line->buf[col] == ' ')
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	return (col);
}
