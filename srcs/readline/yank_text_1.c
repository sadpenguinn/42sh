/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yank_text_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:28:39 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:29:07 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	yank_string(t_matrix *matrix)
{
	t_cursor	pos1;
	t_cursor	pos2;

	pos1.col = get_cursor_pos_end(matrix);
	pos2.col = get_cursor_pos_home(matrix);
	if (pos1.col == pos2.col)
		return (1);
	pos1.row = matrix->cursor->row;
	pos2.row = matrix->cursor->row;
	matrix_string_yank(pos1, pos2);
	return (1);
}

int	yank_begin_word(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_begin_word(matrix);
	if (pos.col == matrix->cursor->col)
		return (1);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_next_word(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_next_word(matrix);
	if (pos.col == matrix->cursor->col)
		return (1);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_end_word(t_matrix *matrix)
{
	t_cursor	pos;
	size_t		col;

	col = matrix->cursor->col;
	matrix->cursor->col = get_cursor_pos_end_word(matrix);
	if (col == matrix->cursor->col)
		return (1);
	pos.col = get_cursor_pos_right(matrix);
	pos.row = matrix->cursor->row;
	matrix->cursor->col = col;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_end(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_end(matrix);
	if (pos.col == matrix->cursor->col)
		return (1);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}
