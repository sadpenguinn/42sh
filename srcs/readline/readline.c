/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:12:10 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/23 08:15:41 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include <unistd.h>
#include "term.h"
#include <stdio.h>
#include "shell.h"
#include "array.h"
#include <time.h>


void     ft_puts(char *buf, int len)
{
	if (len == 0)
		len = strlen(buf);
	write(1, buf, len);
}

int count_string_symbols(char *buf, int n)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < n)
	{
		i += 1 + get_utf_offset_right(buf[i]);
		cnt++;
	}
	return (cnt);
}

int	make_string_from_symbol(char *str, t_uchar c)
{
	int	i;
	int	n;

	i = 0;
	if (c == '\t')
	{
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

void    add_cursor_offset(int offset)
{
	char	str[20];

	if (offset)
	{
		memset(str, 0, 20);
		array_add(CSI, strlen(CSI));
		ft_strnum(str, offset);
		array_add(str, strlen(str));
		array_add("A", 1);
	}
	array_add(CURSOR_MOVE_LINE_START, strlen(CURSOR_MOVE_LINE_START));
}

void reset_line_offset(t_matrix *matrix)
{
	matrix->last_offset = 0;
}

int	change_limits_left_case(t_matrix *matrix, int new_left_limit)
{
	int	size;
	int	i;

	matrix->left_limit = new_left_limit;
	matrix->right_limit = new_left_limit;
	size = g_w.ws_col * g_w.ws_row;
	i = ((matrix->lines[matrix->right_limit]->symbols +
			get_line_prompt_len(matrix->len) - 1)/ g_w.ws_col + 1) * g_w.ws_col;
	while (i <= size && matrix->right_limit < matrix->len - 1)
	{
		matrix->right_limit++;
		i += ((matrix->lines[matrix->right_limit]->symbols +
				get_line_prompt_len(matrix->len) - 1)/ g_w.ws_col + 1) * g_w.ws_col;
	}
	if (i > size)
		matrix->right_limit--;
	return (0);
}

int	change_limits_right_case(t_matrix *matrix, int new_right_limit)
{
	int	size;
	int	i;

	matrix->right_limit = new_right_limit;
	matrix->left_limit = new_right_limit;
	size = g_w.ws_row * g_w.ws_col;
	i = ((matrix->lines[matrix->left_limit]->symbols +
	      get_line_prompt_len(matrix->len) - 1)/ g_w.ws_col + 1) * g_w.ws_col;
	while (i <= size && matrix->left_limit)
	{
		matrix->left_limit--;
		i += ((matrix->lines[matrix->left_limit]->symbols +
		      get_line_prompt_len(matrix->len) - 1)/ g_w.ws_col + 1) * g_w.ws_col;
	}
	if (i > size)
		matrix->left_limit++;
	return (0);
}

void check_cursor_limits(t_matrix *matrix)
{
    int	left_limit;
    int	i;
    int	size;

	size = g_w.ws_row * g_w.ws_col;
    left_limit = matrix->cursor->row;
	i = ((matrix->lines[left_limit]->symbols +
		  get_line_prompt_len(matrix->len) - 1)/ g_w.ws_col + 1) * g_w.ws_col;
	while (i <= size && left_limit)
	{
		left_limit--;
		i += ((matrix->lines[left_limit]->symbols +
			   get_line_prompt_len(matrix->len) - 1)/ g_w.ws_col + 1) * g_w.ws_col;
	}
	if (i > size)
		left_limit++;
	if (left_limit > matrix->left_limit)
		change_limits_right_case(matrix, matrix->cursor->row);
}

int set_matrix_limits(t_matrix *matrix)
{
	check_cursor_limits(matrix);
	if (matrix->cursor->row < matrix->left_limit)
		return (change_limits_left_case(matrix, matrix->cursor->row));
	if (matrix->cursor->row > matrix->right_limit)
		return (change_limits_right_case(matrix, matrix->cursor->row));
	return (change_limits_left_case(matrix, matrix->left_limit));
}

int count_lines_offset(int len)
{
	int i;

	if (len == 1 || len == 0)
		return (0);
	i = 0;
	while (len)
	{
		i++;
		len /= 10;
	}
	return (i);
}

void num_to_str(int max, char *str, int nbr)
{
	int i;

	i = count_lines_offset(max);
	memset(str, 0, i + 1);
	while (nbr && i)
	{
		str[i - 1] = '0' + nbr % 10;
		i--;
		nbr /= 10;
	}
	while (i)
	{
		str[i - 1] = '0';
		i--;
	}
}

int get_line_prompt_len(int max)
{
	return (2 + count_lines_offset(max));
}

void add_lines_prompt_style(void)
{
	array_add(TEXT_BOLD, strlen(TEXT_BOLD));
}

void add_cur_line_prompt_style(void)
{
	array_add(TEXT_BOLD TEXT_COLOR_RED, strlen(TEXT_BOLD) + strlen(TEXT_COLOR_RED));
}

static void	add_line_prefix(t_matrix *matrix, int cur_row)
{
	char str[20];

	memset(str, 0, 20);
	if (cur_row == matrix->cursor->row)
		add_cur_line_prompt_style();
	else
		add_lines_prompt_style();
	num_to_str(matrix->len, str, cur_row + 1);
	array_add(str, strlen(str));
	array_add("> ", 2);
	array_add(COLOR_DEFAULT, strlen(COLOR_DEFAULT));
}

void add_text(t_matrix *matrix, int row, int col)
{
	int	left;

	left = matrix->left_limit;
	reset_line_offset(matrix);
	while (left < row)
	{
		add_line_prefix(matrix, left);
		array_add(matrix->lines[left]->buf, matrix->lines[left]->len);
		if (g_w.ws_col)
		{
			matrix->last_offset += 1 + (matrix->lines[left]->symbols +
					get_line_prompt_len(matrix->len) - 1) / g_w.ws_col;
			array_add("\n", 1);
		}
		left++;
	}
	add_line_prefix(matrix, left);
	array_add(matrix->lines[left]->buf, col);
	if (g_w.ws_col)
	{
		if (col == matrix->lines[row]->len)
		{
			matrix->last_offset += (matrix->lines[left]->symbols +
									get_line_prompt_len(matrix->len)) / g_w.ws_col;
			if ((matrix->lines[left]->symbols
			+ get_line_prompt_len(matrix->len)) % g_w.ws_col == 0)
				array_add("\n", 1);
		}
		else
		{
			matrix->last_offset +=
				(count_string_symbols(matrix->lines[left]->buf, matrix->cursor->col)
				+ get_line_prompt_len(matrix->len)) / g_w.ws_col;
			if ((count_string_symbols(matrix->lines[left]->buf, matrix->cursor->col)
			+ get_line_prompt_len(matrix->len)) % g_w.ws_col == 0)
				array_add("\n", 1);
		}
	}
}

char *matrix_to_string(t_matrix *matrix)
{
	int	i;

	i = 0;
	while (i < matrix->len - 1)
	{
		array_add(matrix->lines[i]->buf, matrix->lines[i]->len);
		array_add("\n", 1);
		i++;
	}
	array_add(matrix->lines[i]->buf, matrix->lines[i]->len);
	return (array_to_string());
}

void add_cursor(t_matrix *matrix)
{
	add_text(matrix, matrix->cursor->row, matrix->cursor->col);
}

void add_lines(t_matrix *matrix)
{
	add_text(matrix, matrix->right_limit, matrix->lines[matrix->right_limit]->len);
}

int print_default(t_matrix *matrix)
{
	set_matrix_limits(matrix);
	add_cursor_offset(matrix->last_offset);
	array_add(CURSOR_CLEAR_TO_END_SCREEN, strlen(CURSOR_CLEAR_TO_END_SCREEN));
	add_lines(matrix);
	add_cursor_offset(matrix->last_offset);
	add_cursor(matrix);
	array_flush();
	return (1);
}

void print_lines(t_matrix *matrix)
{
	set_matrix_limits(matrix);
	add_cursor_offset(matrix->last_offset);
	array_add(CURSOR_CLEAR_TO_END_SCREEN, strlen(CURSOR_CLEAR_TO_END_SCREEN));
	add_lines(matrix);
	array_flush();
}

int autocomplete(t_matrix *matrix)
{
	set_matrix_limits(matrix);
	add_cursor_offset(matrix->last_offset);
	add_lines(matrix);
	if (matrix)
		ft_puts ("\nmain.c  readline.c  array.c\n", 0);
	print_prompt();
	return (1);
}

int newline_handling(t_matrix *matrix)
{
	int	prev_col;
	int	prev_row;

	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] != '\\')
	{
		print_lines(matrix);
		if (!(matrix->len == 1 && matrix->lines[0]->len == 0))
			write(1, "\n", 1);
		return (0);
	}
	prev_col = matrix->cursor->col;
	prev_row = matrix->cursor->row;
	matrix_create_line(matrix, matrix->cursor->row + 1);
	matrix_string_insert(matrix, matrix->cursor,
		matrix->lines[prev_row]->buf + prev_col,
		matrix->lines[prev_row]->len - prev_col);
	matrix->lines[prev_row]->len = prev_col - 1;
	matrix->cursor->col = 0;
	return (1);
}

int     readline_mode(t_matrix *matrix, char *str, t_uchar c)
{
	if (c == BS)
		return (back_space(matrix));
	if (c == '\t' && g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 22)
		return (autocomplete(matrix));
	if (c == '\n')
		return (newline_handling(matrix));
	matrix_string_insert(matrix, matrix->cursor,
		str, make_string_from_symbol(str, c));
	return (1);
}

int check_modes(t_matrix *matrix, t_uchar c)
{
	char	str[9];

	memset(str, 0, 9);
	move_shortcuts(c);
	if (g_mode == READLINE)
		return (readline_mode(matrix, str, c));
	if (g_mode == VI)
		return (readline_mode(matrix, str, c));
	return (1);
}

char *readline(void)
{
	int			ret;
	t_matrix	*matrix;
	char		*str;

	get_term_params(&g_w);
	matrix = init_matrix();
	print_prompt();
	g_mode = READLINE;
	ret = 1;
	set_term();
	while (ret > 0)
	{
		print_default(matrix);
		ret = check_next_symbol(matrix);
	}
	unset_term();
	if (ret == 0)
		str = matrix_to_string(matrix);
	else
		str = NULL;
	matrix_del(&matrix);
	return (str);
}
