/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_string_delete.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:52:49 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:15:46 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <string.h>
#include "libft.h"
#include <stdio.h>

size_t		line_string_delete(t_line *line, size_t pos, size_t size)
{
	if (size == 0)
		return (pos);
	if (size > line->len - pos)
		size = line->len - pos;
	buffer_add(line->buf + pos, size);
	line->symbols -= count_string_symbols(line->buf, pos, pos + size);
	ft_memmove(line->buf + pos, line->buf + pos + size,
			line->len - pos - size);
	ft_memset(line->buf + line->len - size, 0, size);
	line->len -= size;
	return (pos);
}

t_cursor	matrix_string_delete(t_cursor left, t_cursor right)
{
	t_line		*line;
	t_matrix	*matrix;

	check_swap(&left, &right);
	matrix = g_history->matrix[g_history->cur];
	line = matrix->lines[left.row];
	if (left.row == right.row)
	{
		if (g_history->redo_undo == 0)
			action_add(left, right, line->buf + left.col, DELETE);
		line_string_delete(line, left.col, right.col - left.col);
		return (left);
	}
	return (left);
}
