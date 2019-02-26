/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:11:49 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/26 17:00:42 by narchiba         ###   ########.fr       */
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
	return (1);
}
