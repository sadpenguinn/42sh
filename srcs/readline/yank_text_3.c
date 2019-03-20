/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yank_text_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:19:32 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/20 15:19:33 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	yank_find_next_char(t_matrix *matrix)
{
	t_cursor	pos;
	size_t		col;

	col = matrix->cursor->col;
	matrix->cursor->col = get_cursor_pos_find_next_char(matrix);
	if (col == matrix->cursor->col)
		return (1);
	pos.col = get_cursor_pos_right(matrix);
	pos.row = matrix->cursor->row;
	matrix->cursor->col = col;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_find_back_char(t_matrix *matrix)
{
	t_cursor	pos;
	size_t		col;

	col = matrix->cursor->col;
	matrix->cursor->col = get_cursor_pos_find_back_char(matrix);
	if (col == matrix->cursor->col)
		return (1);
	pos.col = matrix->cursor->col;
	pos.row = matrix->cursor->row;
	matrix->cursor->col = col;
	matrix_string_yank(*matrix->cursor, pos);
	return (1);
}

int	yank_find_char_usual_order(t_matrix *matrix)
{
	char	c;

	c = g_history->prev_find_option;
	if (c != 'f' && c != 'F')
		return (1);
	if (c == 'f')
		return (yank_find_next_char(matrix));
	return (yank_find_back_char(matrix));
}

int	yank_find_char_reverse_order(t_matrix *matrix)
{
	char	c;

	c = g_history->prev_find_option;
	if (c != 'f' && c != 'F')
		return (1);
	if (c == 'F')
		return (yank_find_next_char(matrix));
	return (yank_find_back_char(matrix));
}
