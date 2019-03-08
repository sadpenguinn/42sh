/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:56:46 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:19:38 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <unistd.h>

static void	count_quotes(t_matrix *matrix, char *buf, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (buf[i] == '\'')
		{
			if (matrix->single_quotes == 1)
				matrix->single_quotes = 0;
			else if (matrix->double_quotes == 0)
				matrix->single_quotes = 1;
		}
		if (buf[i] == '"')
		{
			if (matrix->double_quotes == 1)
				matrix->double_quotes = 0;
			else if (matrix->single_quotes == 0)
				matrix->double_quotes = 1;
		}
		i++;
	}
}

static int	check_quotes(t_matrix *matrix)
{
	size_t i;

	i = 0;
	matrix->single_quotes = 0;
	matrix->double_quotes = 0;
	while (i < matrix->len)
	{
		count_quotes(matrix, matrix->lines[i]->buf, matrix->lines[i]->len);
		i++;
	}
	if (matrix->single_quotes || matrix->double_quotes)
		return (0);
	return (1);
}

static int	quotes_handling(t_matrix *matrix)
{
	if (check_quotes(matrix))
		return (0);
	matrix_create_line(matrix, matrix->len);
	return (1);
}

int			newline_handling(t_matrix *matrix)
{
	size_t	prev_col;
	size_t	prev_row;
	t_line	*line;

	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] != '\\')
		return (quotes_handling(matrix));
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
