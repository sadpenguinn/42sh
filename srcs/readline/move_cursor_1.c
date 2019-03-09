/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:11:49 by sitlcead          #+#    #+#             */
/*   Updated: 2019/03/03 18:05:28 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	move_cursor_left(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_left(matrix);
	return (1);
}

int	move_cursor_right(t_matrix *matrix)
{
	matrix->cursor->col = get_cursor_pos_right(matrix);
	return (1);
}

int	move_cursor_up(t_matrix *matrix)
{
	size_t	col;
	size_t	symbols;
	t_line	*line;

	if (matrix->cursor->row)
	{
		line = matrix->lines[matrix->cursor->row];
		symbols = count_string_symbols(line->buf, 0, matrix->cursor->col);
		matrix->cursor->row--;
		line = matrix->lines[matrix->cursor->row];
		symbols = (symbols < line->symbols) ? symbols : line->symbols;
		col = count_string_cols(line->buf, symbols);
		matrix->cursor->col = col;
	}
	else
		return (move_history_prev());
	return (1);
}

int	move_cursor_down(t_matrix *matrix)
{
	size_t	col;
	size_t	symbols;
	t_line	*line;

	if (matrix->cursor->row != matrix->len - 1)
	{
		line = matrix->lines[matrix->cursor->row];
		symbols = count_string_symbols(line->buf, 0, matrix->cursor->col);
		matrix->cursor->row++;
		line = matrix->lines[matrix->cursor->row];
		symbols = (symbols < line->symbols) ? symbols : line->symbols;
		col = count_string_cols(line->buf, symbols);
		matrix->cursor->col = col;
	}
	else
		return (move_history_next());
	return (1);
}
