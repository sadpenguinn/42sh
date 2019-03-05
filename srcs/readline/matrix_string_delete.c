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

void	matrix_string_delete(t_cursor left, t_cursor right)
{
	t_line		*line;
	int			i;
	int			symbols;
	t_matrix	*matrix;

	check_swap(&left, &right);
	matrix = g_history->cur_matrix;
	line = matrix->lines[left.row];
	if (left.row == right.row)
	{
		i = left.col;
		symbols = 0;
		while (i < right.col)
		{
			i += 1 + get_utf_offset_right(line->buf[i]);
			symbols++;
		}
		buffer_free();
		buffer_add(line->buf + left.col,
				   right.col - left.col);
		ft_memmove(line->buf + left.col, line->buf + i,
			line->len - i);
		line->len -= i - left.col;
		line->symbols -= symbols;
	}
}
