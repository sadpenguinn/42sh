#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "readline.h"
#include <unistd.h>
#include "term.h"
#include <stdio.h>
#include "shell.h"
#include "array.h"
#include <time.h>

t_uchar     g_comb[4];

void     ft_puts(char *buf, int len)
{
	if (len == 0)
		len = strlen(buf);
	write(1, buf, len);
}

void    comb_offset(t_uchar c)
{
	g_comb[0] = g_comb[1];
	g_comb[1] = g_comb[2];
	g_comb[2] = g_comb[3];
	g_comb[3] = c;
}

void    line_string_insert(t_line *line, const char *str, int size, t_cursor *cursor)
{
	if (line->len + size > line->size)
		line_resize(line, line->len + size + line->size * RATIO, line->size);
	if (cursor->col < line->len)
		memmove(line->buf + cursor->col + size, line->buf + cursor->col,
				line->len - cursor->col);
	memcpy(line->buf + cursor->col, str, size);
	cursor->col += size;
	line->len += size;
}

void    matrix_line_insert(t_matrix *matrix, int pos)
{
	if (matrix->len == matrix->size)
		matrix_resize(matrix, matrix->size * RATIO, matrix->size);
	if (pos < matrix->len)
		memmove(matrix->lines + pos + 1, matrix->lines + pos,
				(matrix->len - pos) * sizeof(t_line *));
	matrix->lines[pos] = init_line();
	matrix->len++;
}

void    matrix_string_insert(t_matrix *matrix, const char *str)
{
	int j;
	int size;
	t_line *line;
	int symbols;

	line = matrix->lines[matrix->cursor->row];
	j = 0;
	while (str[j])
	{
		symbols = 0;
		size = 0;
		while (str[j + size] != '\n' && str[j + size])
		{
			size += 1 + get_utf_offset(str[j]);
			symbols++;
		}
		line_string_insert(line, str, size, matrix->cursor);
		line->symbols += symbols;
		j += size;
	}
}

void    make_string_from_symbol(char *str, t_uchar c)
{
	int i;
	int n;

	i = 0;
	if (c == '\t')
	{
		while (i < 4)
			str[i++] = ' ';
		return ;
	}
	n = get_utf_offset(*((char *)&c));
	while (i <= n)
	{
		str[i] = ((c >> (i * 8)) & 0xFF);
		i++;
	}
}

void    add_offset(int offset)
{
	int i;

	i = 0;
	while (i < offset)
	{
		array_add(CSI "1A", 0);
		i++;
	}
	array_add(CURSOR_MOVE_LINE_START, 0);
}

int count_chars(char *buf, int n)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (i < n)
	{
		i += 1 + get_utf_offset(buf[i]);
		cnt++;
	}
	return (cnt);
}

void reset_line_offset(t_matrix *matrix)
{
	matrix->last_offset = 0;
}

int get_line_prompt_len(t_matrix *matrix)
{
	(void)matrix;
	return (2);
}

void change_limits_left_case(t_matrix *matrix, int new_left_limit)
{
	int size;
	int i;

	matrix->left_limit = new_left_limit;
	matrix->right_limit = new_left_limit;
	size = g_w.ws_col * g_w.ws_row;
	i = ((matrix->lines[matrix->right_limit]->symbols +
			get_line_prompt_len(matrix) - 1)/ g_w.ws_col + 1) * g_w.ws_col;
	while (i <= size && matrix->right_limit < matrix->len - 1)
	{
		matrix->right_limit++;
		i += ((matrix->lines[matrix->right_limit]->symbols +
				get_line_prompt_len(matrix) - 1)/ g_w.ws_col + 1) * g_w.ws_col;
	}
	if (i > size)
		matrix->right_limit--;
}

void change_limits_right_case(t_matrix *matrix, int new_right_limit)
{
	int size;
	int i;

	matrix->right_limit = new_right_limit;
	matrix->left_limit = new_right_limit;
	size = g_w.ws_row * g_w.ws_col;
	i = ((matrix->lines[matrix->left_limit]->symbols +
	      get_line_prompt_len(matrix) - 1)/ g_w.ws_col + 1) * g_w.ws_col;
	while (i <= size && matrix->left_limit)
	{
		matrix->left_limit--;
		i += ((matrix->lines[matrix->left_limit]->symbols +
		      get_line_prompt_len(matrix) - 1)/ g_w.ws_col + 1) * g_w.ws_col;
	}
	if (i > size)
		matrix->left_limit++;
}

void check_cursor_limits(t_matrix *matrix)
{
    int left_limit;
    int i;
    int size;

	size = g_w.ws_row * g_w.ws_col;
    left_limit = matrix->cursor->row;
	i = ((matrix->lines[left_limit]->symbols +
		  get_line_prompt_len(matrix) - 1)/ g_w.ws_col + 1) * g_w.ws_col;
	while (i <= size && left_limit)
	{
		left_limit--;
		i += ((matrix->lines[left_limit]->symbols +
			   get_line_prompt_len(matrix) - 1)/ g_w.ws_col + 1) * g_w.ws_col;
	}
	if (i > size)
		left_limit++;
	if (left_limit > matrix->left_limit)
		change_limits_right_case(matrix, matrix->cursor->row);
}

void set_matrix_limits(t_matrix *matrix)
{
	check_cursor_limits(matrix);
	if (matrix->cursor->row < matrix->left_limit)
		change_limits_left_case(matrix, matrix->cursor->row);
	if (matrix->cursor->row > matrix->right_limit)
		change_limits_right_case(matrix, matrix->cursor->row);
}

void add_text(t_matrix *matrix, int row, int col)
{
	int left;

	left = matrix->left_limit;
	reset_line_offset(matrix);
	while (left < row)
	{
		array_add("> ", 0);
		array_add(matrix->lines[left]->buf, matrix->lines[left]->len);
		if (g_w.ws_col)
		{
			matrix->last_offset += 1 + (matrix->lines[left]->symbols +
					get_line_prompt_len(matrix) - 1) / g_w.ws_col;
			array_add("\n", 1);
		}
		left++;
	}
	array_add("> ", 0);
	if (g_w.ws_col)
	{
		if (col == matrix->lines[row]->len)
			matrix->last_offset += (matrix->lines[left]->symbols +
					get_line_prompt_len(matrix) - 1) / g_w.ws_col;
		else
			matrix->last_offset +=
					(count_chars(matrix->lines[left]->buf, matrix->cursor->col)
					+ get_line_prompt_len(matrix) - 1) / g_w.ws_col;
	}
	if (col)
		array_add(matrix->lines[left]->buf, col);
}

char *matrix_to_string(t_matrix *matrix)
{
	int i;

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

void print_default(t_matrix *matrix)
{
	set_matrix_limits(matrix);
	add_offset(matrix->last_offset);
	array_add(CURSOR_CLEAR_TO_END_SCREEN, 0);
	add_lines(matrix);
	add_offset(matrix->last_offset);
	add_cursor(matrix);
	array_flush();
}

void    auto_complete(t_matrix *matrix)
{
	set_matrix_limits(matrix);
	add_offset(matrix->last_offset);
	add_lines(matrix);
	if (matrix)
		ft_puts ("\nmain.c  readline.c  array.c\n", 0);
	print_prompt();
}

int     readline_mode(t_matrix *matrix, char *str, t_uchar c)
{
	if (c == '\t' && g_comb[2] == 22)
	{
		auto_complete(matrix);
		add_lines(matrix);
		array_flush();
		return (1);
	}
	if (c == '\n')
	{
		if (g_comb[2] != '\\')
		{
			if (!(matrix->len == 1 && matrix->lines[0]->len == 0))
				write(1, "\n", 1);
			return (0);
		}
		matrix->lines[matrix->cursor->row]->len = matrix->cursor->col - 1;
		matrix_line_insert(matrix, matrix->cursor->row + 1);
		matrix->cursor->row += 1;
		matrix->cursor->col = 0;
	}
	else
	{
		make_string_from_symbol(str, c);
		matrix_string_insert(matrix, str);
	}
	print_default(matrix);
	return (1);
}

int check_modes(t_matrix *matrix, t_uchar c)
{
	char str[9];

	memset(str, 0, 9);
	if (g_mode == READLINE)
		return (readline_mode(matrix, str, c));
	if (g_mode == VI)
		return (readline_mode(matrix, str, c));
	return (1);
}

char *readline(void)
{
	int ret;
	t_matrix *matrix;
	char *str;

	get_term_params(&g_w);
	matrix = init_matrix();
	print_prompt();
	print_default(matrix);
	g_mode = READLINE;
	ret = 1;
	set_term();
	while (ret > 0)
		ret = check_next_symbol(matrix);
	unset_term();
	if (ret == 0)
	{
		str = matrix_to_string(matrix);
		return (str);
	}
	return (NULL);
}
