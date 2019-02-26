/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:50:36 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 16:51:36 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int		back_space(t_matrix *matrix)
{
	int		col;
	t_line	*line;

	if (matrix->cursor->col == 0 && matrix->cursor->row != 0)
	{
		matrix->cursor->row--;
		matrix->cursor->col = matrix->lines[matrix->cursor->row]->len;
		line = matrix->lines[matrix->cursor->row + 1];
		col = matrix->cursor->col;
		matrix_string_insert(matrix, matrix->cursor, line->buf, line->len);
		matrix_erase_line(matrix, matrix->cursor->row + 1);
		matrix->cursor->col = col;
	}
	else if (matrix->cursor->col != 0)
	{
		move_cursor_left(matrix);
		line = matrix->lines[matrix->cursor->row];
		col = matrix->cursor->col +
			1 + get_utf_offset_right(line->buf[matrix->cursor->col]);
		matrix_string_delete(matrix, matrix->cursor->row, col);
	}
	return (1);
}

int		del(t_matrix *matrix)
{
	int		col;
	t_line	*line;

	if (matrix->cursor->col == matrix->lines[matrix->cursor->row]->len &&
		matrix->cursor->row != matrix->len - 1)
	{
		line = matrix->lines[matrix->cursor->row + 1];
		col = matrix->cursor->col;
		matrix_string_insert(matrix, matrix->cursor, line->buf, line->len);
		matrix_erase_line(matrix, matrix->cursor->row + 1);
		matrix->cursor->col = col;
	}
	else if (matrix->cursor->col != matrix->lines[matrix->cursor->row]->len)
	{
		line = matrix->lines[matrix->cursor->row];
		col = matrix->cursor->col +
			1 + get_utf_offset_right(line->buf[matrix->cursor->col]);
		matrix_string_delete(matrix, matrix->cursor->row, col);
	}
	return (1);
}
