/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:36:43 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 18:53:37 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

void	add_line(t_line *line, size_t start, size_t end, size_t row)
{
	size_t	left;
	size_t	right;

	array_add(TEXT_UNBOLD, ft_strlen(TEXT_UNBOLD));
	array_add(DEFAULT_TEXT_COLORS, ft_strlen(DEFAULT_TEXT_COLORS));
	array_add(TURN_ON_CURSOR, ft_strlen(TURN_ON_CURSOR));
	while (start < end)
	{
		start = add_spaces(line, start, end, row);
		left = get_space_left_pos(line->buf, start);
		right = get_space_right_pos(line->buf, start, line->len);
		if (lex_check_bash_word(line->buf + left, right - left) && g_syntax)
			array_add(TEXT_COLOR_YELLOW, ft_strlen(TEXT_COLOR_YELLOW));
		start = add_non_spaces(line, start, end, row);
		array_add(DEFAULT_TEXT_COLORS, ft_strlen(DEFAULT_TEXT_COLORS));
	}
	array_add(CSI_DEFAULT, ft_strlen(CSI_DEFAULT));
	array_add(DEFAULT_TERM_COLORS, ft_strlen(DEFAULT_TERM_COLORS));
}

void	add_text(t_matrix *matrix, size_t row, size_t col)
{
	size_t	left;
	size_t	symbols;

	left = matrix->left_limit;
	while (left < row)
	{
		add_line_prefix(matrix, left);
		add_line(matrix->lines[left], 0, matrix->lines[left]->len, left);
		g_history->last_offset += 1 + (matrix->lines[left]->symbols +
				get_lines_prompt_len(matrix->len) - 1) / g_w.ws_col;
		array_add("\n", 1);
		left++;
	}
	add_line_prefix(matrix, left);
	add_line(matrix->lines[left], 0, col, left);
	symbols = (col == matrix->lines[left]->len) ?
		matrix->lines[left]->symbols :
		count_string_symbols(matrix->lines[left]->buf, 0, col);
	symbols += get_lines_prompt_len(matrix->len);
	g_history->last_offset += symbols / g_w.ws_col;
	if (symbols % g_w.ws_col == 0)
		array_add("\n", 1);
	array_add(CSI_DEFAULT, ft_strlen(CSI_DEFAULT));
	array_add(DEFAULT_TERM_COLORS, ft_strlen(DEFAULT_TERM_COLORS));
}

void	add_cursor_text(t_matrix *matrix)
{
	add_text(matrix, matrix->cursor->row, matrix->cursor->col);
}

void	add_lines_text(t_matrix *matrix)
{
	add_text(matrix, matrix->right_limit,
			matrix->lines[matrix->right_limit]->len);
}
