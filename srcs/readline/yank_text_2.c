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
	int col1;
	int col2;

	col1 = get_cursor_pos_end(matrix);
	col2 = matrix->cursor->col;
	matrix->cursor->col = get_cursor_pos_home(matrix);
	matrix_string_yank(matrix, matrix->cursor->row, col1);
	matrix->cursor->col = col2;
	return (1);
}

int	yank_begin_alnum(t_matrix *matrix)
{
	int col;

	col = get_cursor_pos_begin_alnum(matrix);
	matrix_string_yank(matrix, matrix->cursor->row, col);
	return (1);
}

int	yank_next_alnum(t_matrix *matrix)
{
	int col;

	col = get_cursor_pos_next_alnum(matrix);
	matrix_string_yank(matrix, matrix->cursor->row, col);
	return (1);
}

int	yank_end_alnum(t_matrix *matrix)
{
	int col;

	col = get_cursor_pos_end_alnum(matrix);
	matrix_string_yank(matrix, matrix->cursor->row, col);
	return (1);
}
