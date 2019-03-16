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

static int	ft_is_non_alnumspace(char c)
{
	if (!ft_isalnum(c) && c != ' ')
		return (1);
	return (0);
}

size_t		get_cursor_pos_next_alnum(t_matrix *matrix)
{
	size_t	col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	if (col < line->len && line->buf[col] == ' ')
		col += 1 + get_utf_offset_right(line->buf[col]);
	if (col < line->len && ft_isalnum(line->buf[col]))
	{
		while (col < line->len && ft_isalnum(line->buf[col]))
			col += 1 + get_utf_offset_right(line->buf[col]);
	}
	else
	{
		while (col < line->len && ft_is_non_alnumspace(line->buf[col]))
			col += 1 + get_utf_offset_right(line->buf[col]);
	}
	while (col < line->len && line->buf[col] == ' ')
		col += 1 + get_utf_offset_right(line->buf[col]);
	return (col);
}

size_t		get_cursor_pos_begin_alnum(t_matrix *matrix)
{
	size_t	col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	if (col && line->buf[col] != ' ')
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	while (col && line->buf[col] == ' ')
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	if (col && ft_isalnum(line->buf[col]))
	{
		while (col && ft_isalnum(line->buf[col]))
			col -= 1 + get_utf_offset_left(line->buf, col - 1);
	}
	else
	{
		while (col && ft_is_non_alnumspace(line->buf[col]))
			col -= 1 + get_utf_offset_left(line->buf, col - 1);
	}
	if (line->buf[col] == ' ')
		col += 1 + get_utf_offset_right(line->buf[col]);
	return (col);
}

size_t		get_cursor_pos_end_alnum(t_matrix *matrix)
{
	size_t	col;
	t_line	*line;

	col = matrix->cursor->col;
	line = matrix->lines[matrix->cursor->row];
	if (col < line->len && line->buf[col] != ' ')
		col += 1 + get_utf_offset_right(line->buf[col]);
	while (col < line->len - 1 && line->buf[col] == ' ')
		col += 1 + get_utf_offset_right(line->buf[col]);
	if (col < line->len - 1 && ft_isalnum(line->buf[col]))
	{
		while (col < line->len - 1 && ft_isalnum(line->buf[col]))
			col += 1 + get_utf_offset_right(line->buf[col]);
	}
	else
	{
		while (col < line->len - 1 && ft_is_non_alnumspace(line->buf[col]))
			col += 1 + get_utf_offset_right(line->buf[col]);
	}
	if (col < line->len && line->buf[col] == ' ')
		col -= 1 + get_utf_offset_left(line->buf, col - 1);
	return (col);
}

size_t	get_cursor_pos_find_char_usual_order(t_matrix *matrix)
{
	char	c;

	c = g_history->prev_find_option;
	if (c != 'f' && c != 'F')
		return (matrix->cursor->col);
	if (c == 'f')
		return (get_cursor_pos_find_next_char(matrix));
	return (get_cursor_pos_find_back_char(matrix));
}

size_t	get_cursor_pos_find_char_reverse_order(t_matrix *matrix)
{
	char	c;

	c = g_history->prev_find_option;
	if (c != 'f' && c != 'F')
		return (matrix->cursor->col);
	if (c == 'F')
		return (get_cursor_pos_find_next_char(matrix));
	return (get_cursor_pos_find_back_char(matrix));
}
