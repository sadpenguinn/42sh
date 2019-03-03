/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:11:49 by sitlcead          #+#    #+#             */
/*   Updated: 2019/03/03 06:43:48 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	move_cursor_left(t_matrix *matrix)
{
	if (matrix->cursor->col != 0)
		matrix->cursor->col -= 1 +
			get_utf_offset_left(matrix->lines[matrix->cursor->row]->buf,
				matrix->cursor->col - 1);
	return (1);
}

int	move_cursor_right(t_matrix *matrix)
{
	if (matrix->cursor->col != matrix->lines[matrix->cursor->row]->len)
		matrix->cursor->col += 1 +
			get_utf_offset_right(*(matrix->lines[matrix->cursor->row]->buf +
				matrix->cursor->col));
	return (1);
}

int	move_cursor_up(t_matrix *matrix)
{
	int		col;
	int		symbols;
	t_line	*line;

	if (matrix->cursor->row)
	{
		line = matrix->lines[matrix->cursor->row];
		symbols = count_string_symbols(line->buf, matrix->cursor->col);
		matrix->cursor->row--;
		line = matrix->lines[matrix->cursor->row];
		symbols = (symbols < line->symbols) ? symbols : line->symbols;
		col = count_string_cols(line->buf, symbols);
		matrix->cursor->col = col;
	}
	else
	{
		move_history_prev();
		g_history->tmp->cursor->row = 0;
		g_history->tmp->cursor->col = 0;
	}
	return (1);
}

int	move_cursor_down(t_matrix *matrix)
{
	int		col;
	int		symbols;
	t_line	*line;

	if (matrix->cursor->row != matrix->len - 1)
	{
		line = matrix->lines[matrix->cursor->row];
		symbols = count_string_symbols(line->buf, matrix->cursor->col);
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
