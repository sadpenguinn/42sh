/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yank_text_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:29:11 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:29:26 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	yank_begin_alnum(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_begin_alnum(matrix);
	if (pos.col == matrix->cursor->col)
		return (1);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_next_alnum(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_next_alnum(matrix);
	if (pos.col == matrix->cursor->col)
		return (1);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_end_alnum(t_matrix *matrix)
{
	t_cursor	pos;
	size_t		col;

	col = matrix->cursor->col;
	matrix->cursor->col = get_cursor_pos_end_alnum(matrix);
	if (col == matrix->cursor->col)
		return (1);
	pos.col = get_cursor_pos_right(matrix);
	pos.row = matrix->cursor->row;
	matrix->cursor->col = col;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_home(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_home(matrix);
	if (pos.col == matrix->cursor->col)
		return (1);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_begin(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_begin(matrix);
	if (pos.col == matrix->cursor->col)
		return (1);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}
