/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:36:43 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 16:46:17 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "array.h"

void	add_cursor_text(t_matrix *matrix)
{
	add_text(matrix, matrix->cursor->row, matrix->cursor->col);
}

void	add_lines_text(t_matrix *matrix)
{
	add_text(matrix, matrix->right_limit,
			matrix->lines[matrix->right_limit]->len);
}

void	add_text(t_matrix *matrix, int row, int col)
{
	int	left;
	int symbols;

	left = matrix->left_limit;
	matrix->last_offset = 0;
	while (left < row)
	{
		add_line_prefix(matrix, left);
		array_add(matrix->lines[left]->buf, matrix->lines[left]->len);
		matrix->last_offset += 1 + (matrix->lines[left]->symbols +
				get_lines_prompt_len(matrix->len) - 1) / g_w.ws_col;
		array_add("\n", 1);
		left++;
	}
	add_line_prefix(matrix, left);
	array_add(matrix->lines[left]->buf, col);
	symbols = (col == matrix->lines[left]->len) ?
		matrix->lines[left]->symbols :
		count_string_symbols(matrix->lines[left]->buf, col);
	symbols += get_lines_prompt_len(matrix->len);
	matrix->last_offset += symbols / g_w.ws_col;
	if (symbols % g_w.ws_col == 0)
		array_add("\n", 1);
}
