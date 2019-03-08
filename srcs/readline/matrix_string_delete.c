/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_string_delete.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:52:49 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/03 17:46:00 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <string.h>
#include "libft.h"
#include <stdio.h>

static void	check_swap(t_cursor *start, t_cursor *end)
{
	t_cursor	tmp;

	if (start->row > end->row ||
		(start->row == end->row && start->col > end->col))
	{
		tmp.row = start->row;
		tmp.col = start->col;
		start->row = end->row;
		start->col = end->col;
		end->row = tmp.row;
		end->col = tmp.col;
	}
}

int			line_string_delete(t_line *line, int pos, int size)
{
	if (size <= 0 || pos < 0)
		return (pos);
	if (size > line->len - pos)
		size = line->len - pos;
	buffer_free();
	buffer_add(line->buf + pos, size);
	line->symbols -= count_string_symbols(line->buf, size);
	ft_memmove(line->buf + pos, line->buf + pos + size,
			   line->len - pos - size);
	line->len -= size;
	return (pos);
}

void	matrix_string_delete(t_cursor left, t_cursor right)
{
	t_line		*line;
	t_matrix	*matrix;

	check_swap(&left, &right);
	matrix = g_history->matrix[g_history->cur];
	line = matrix->lines[left.row];
	if (left.row == right.row)
		line_string_delete(line, left.col, right.col - left.col);
}
