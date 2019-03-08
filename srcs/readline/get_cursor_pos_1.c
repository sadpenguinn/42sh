/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cursor_pos_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:54:25 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 12:56:42 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	get_cursor_pos_home(t_matrix *matrix)
{
	(void)matrix;
	return (0);
}

int	get_cursor_pos_begin(t_matrix *matrix)
{
	int		col;
	t_line	*line;

	line = matrix->lines[matrix->cursor->row];
	col = 0;
	while (line->buf[col] == ' ' && col < line->len)
		col += 1 + get_utf_offset_right(line->buf[col]);
	return (col);
}

int	get_cursor_pos_end(t_matrix *matrix)
{
	return (matrix->lines[matrix->cursor->row]->len);
}

int	get_cursor_pos_left(t_matrix *matrix)
{
	if (matrix->cursor->col)
		return (matrix->cursor->col - (1 +
					get_utf_offset_left(matrix->lines[matrix->cursor->row]->buf,
						matrix->cursor->col - 1)));
		return (0);
}

int	get_cursor_pos_right(t_matrix *matrix)
{
	if (matrix->cursor->col != matrix->lines[matrix->cursor->row]->len)
		return (matrix->cursor->col + 1 +
				get_utf_offset_right(*(matrix->lines[matrix->cursor->row]->buf
						+ matrix->cursor->col)));
		return (matrix->lines[matrix->cursor->row]->len);
}
