/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cursor_pos_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:58:24 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 12:58:37 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

int	get_cursor_pos_next_alnum(t_matrix *matrix)
{
	int		col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	while (ft_isalnum(line->buf[col]) && col < line->len)
		col += 1 + get_utf_offset_right(line->buf[col]);
	while (!ft_isalnum(line->buf[col]) && col < line->len)
		col += 1 + get_utf_offset_right(line->buf[col]);
	return (col);
}

int	get_cursor_pos_begin_alnum(t_matrix *matrix)
{
	int		col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	if (ft_isalnum(line->buf[col]) && col)
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	while (!ft_isalnum(line->buf[col]) && col)
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	while (ft_isalnum(line->buf[col]) && col)
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	if (!ft_isalnum(line->buf[col]))
		col += 1 + get_utf_offset_right(line->buf[col]);
	return (col);
}

int	get_cursor_pos_end_alnum(t_matrix *matrix)
{
	int		col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	if (ft_isalnum(line->buf[col]) && col < line->len)
		col += 1 + get_utf_offset_right(line->buf[col]);
	while (!ft_isalnum(line->buf[col]) && col < line->len - 1)
		col += 1 + get_utf_offset_right(line->buf[col]);
	while (ft_isalnum(line->buf[col]) && col < line->len - 1)
		col += 1 + get_utf_offset_right(line->buf[col]);
	if (col < line->len && !ft_isalnum(line->buf[col]))
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	return (col);
}
