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

int	yank_string(t_matrix *matrix)
{
	t_cursor	pos1;
	t_cursor	pos2;

	pos1.col = get_cursor_pos_end(matrix);
	pos2.col = get_cursor_pos_home(matrix);
	pos1.row = matrix->cursor->row;
	pos2.row = matrix->cursor->row;
	matrix_string_yank(pos1, pos2);
	return (1);
}

int	yank_begin_alnum(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_begin_alnum(matrix);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_next_alnum(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_next_alnum(matrix);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_end_alnum(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_end_alnum(matrix);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}
