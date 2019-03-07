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
#include "libft.h"

int		get_space_left_pos(const char *buf, int pos)
{
	while (pos && buf[pos - 1] != '\t' && buf[pos - 1] != ' ')
		pos--;
	return (pos);
}

int 	get_space_right_pos(const char *buf, int pos, int len)
{
	while (pos < len && buf[pos] != '\t' && buf[pos] != ' ')
		pos++;
	return (pos);
}

static void	add_line(t_line	*line, int start, int end)
{
	int	left;
	int	right;
	int	pos;

	array_add(TEXT_BOLD, strlen(TEXT_BOLD));
	array_add(DEFAULT_TERM_COLORS, strlen(DEFAULT_TERM_COLORS));
	array_add(TURN_ON_CURSOR, strlen(TURN_ON_CURSOR));
	while (start < end)
	{
		pos = start;
		while (pos < end && line->buf[pos] == ' ')
			pos++;
		array_add(line->buf + start, pos - start);
		start = pos;
		left = get_space_left_pos(line->buf, start);
		right = get_space_right_pos(line->buf, start, line->len);
		if (lex_check_bash_word(line->buf + left, right - left))
			array_add(TEXT_COLOR_YELLOW, strlen(TEXT_COLOR_YELLOW));
		while (pos < end && line->buf[pos] != ' ')
			pos++;
		array_add(line->buf + start, pos - start);
		array_add(DEFAULT_TERM_COLORS, strlen(DEFAULT_TERM_COLORS));
		start = pos;
	}
}

void	add_text(t_matrix *matrix, int row, int col)
{
	int	left;
	int symbols;

	left = matrix->left_limit;
	while (left < row)
	{
		add_line_prefix(matrix, left);
		add_line(matrix->lines[left], 0, matrix->lines[left]->len);
		g_history->last_offset += 1 + (matrix->lines[left]->symbols +
				get_lines_prompt_len(matrix->len) - 1) / g_w.ws_col;
		array_add("\n", 1);
		left++;
	}
	add_line_prefix(matrix, left);
	add_line(matrix->lines[left], 0, col);
	symbols = (col == matrix->lines[left]->len) ?
		matrix->lines[left]->symbols :
		count_string_symbols(matrix->lines[left]->buf, col);
	symbols += get_lines_prompt_len(matrix->len);
	g_history->last_offset += symbols / g_w.ws_col;
	if (symbols % g_w.ws_col == 0)
		array_add("\n", 1);
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
