/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:56:46 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/09 11:02:04 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <unistd.h>

static int	end_handling(t_matrix *matrix)
{
	int	ret;

	matrix_to_string(matrix, matrix->str_history);
	if (are_quotes(matrix->str_history->buf, matrix->str_history->len))
	{
		matrix_create_line(matrix, matrix->len);
		return (1);
	}
	ret = bang_handling(matrix);
	if (ret == NO_BANGS || ret == BANG_ERROR)
		return (0);
	return (1);
}

int			newline_handling(t_matrix *matrix)
{
	size_t	prev_col;
	size_t	prev_row;
	t_line	*line;

	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] != '\\')
		return (end_handling(matrix));
	prev_col = matrix->cursor->col;
	prev_row = matrix->cursor->row;
	line = matrix->lines[prev_row];
	matrix_create_line(matrix, matrix->cursor->row + 1);
	if (prev_col != line->len)
	{
		matrix_string_insert(matrix, *matrix->cursor,
				line->buf + prev_col, line->len - prev_col);
		matrix->cursor->col = 0;
	}
	line->len = prev_col - 1;
	line->symbols = count_string_symbols(line->buf, line->len);
	return (1);
}
