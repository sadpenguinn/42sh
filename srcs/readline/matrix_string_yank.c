/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_string_yank.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:17:14 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:17:25 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

size_t	line_string_yank(t_line *line, size_t pos, size_t size)
{
	if (size == 0)
		return (pos);
	buffer_free();
	buffer_add(line->buf + pos, size);
	return (pos + size);
}

void	matrix_string_yank(t_cursor left, t_cursor right)
{
	t_line		*line;
	t_matrix	*matrix;

	check_swap(&left, &right);
	matrix = g_history->matrix[g_history->cur];
	line = matrix->lines[left.row];
	if (left.row == right.row)
		line_string_yank(line, left.col, right.col - left.col);
}
