/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_string_delete.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:52:49 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/03 06:15:16 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <string.h>

void	matrix_string_delete(t_matrix *matrix, int row, int col)
{
	t_line	*line;
	int		i;
	int		symbols;

	line = matrix->lines[matrix->cursor->row];
	if (row == matrix->cursor->row)
	{
		i = matrix->cursor->col;
		symbols = 0;
		while (i < col)
		{
			i += 1 + get_utf_offset_right(line->buf[i]);
			symbols++;
		}
		memmove(line->buf + matrix->cursor->col, line->buf + i,
			line->len - i);
		line->len -= i - matrix->cursor->col;
		line->symbols -= symbols;
	}
}
