/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:05:38 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 18:29:22 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	symbol_to_string(t_matrix *matrix, t_uchar c, char *str)
{
	int		i;
	int		n;
	t_line	*line;
	int		col;

	i = 0;
	if (c == '\t')
	{
		line = matrix->lines[matrix->cursor->row];
		col = matrix->cursor->col;
		matrix->cursor->col -= 1 +
				get_utf_offset_left(line->buf, matrix->cursor->col - 1);
		matrix_string_delete(matrix, matrix->cursor->row, col);
		while (i < 4)
			str[i++] = ' ';
		return (i);
	}
	n = get_utf_offset_right(*((char *)&c));
	while (i <= n)
	{
		str[i] = ((c >> (i * 8)) & 0xFF);
		i++;
	}
	return (i);
}
