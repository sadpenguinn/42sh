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

void	matrix_string_yank(t_matrix *matrix, size_t row, size_t col)
{
	t_line		*line;
	t_cursor	cursor;

	cursor.row = matrix->cursor->row;
	cursor.col = matrix->cursor->col;
	if (cursor.row > row || (cursor.row == row && cursor.col > col))
	{
		cursor.row = row;
		cursor.col = col;
		row = matrix->cursor->row;
		col = matrix->cursor->col;
	}
	if (cursor.row == row)
	{
		line = matrix->lines[cursor.row];
		buffer_free();
		buffer_add(line->buf + cursor.col,
				col - cursor.col);
	}
}
