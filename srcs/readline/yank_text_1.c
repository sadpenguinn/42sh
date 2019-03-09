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

int	yank_begin_word(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_begin_word(matrix);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_next_word(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_next_word(matrix);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_end_word(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_end_word(matrix);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_end(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_end(matrix);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_home(t_matrix *matrix)
{
	t_cursor	pos;

	pos.col = get_cursor_pos_home(matrix);
	pos.row = matrix->cursor->row;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}
