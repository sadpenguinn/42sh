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

void    line_resize(t_line *line, int new_size, int old_size)
{
	line->buf = (char *)xrealloc(line->buf, new_size + 1, old_size);
	line->size = new_size;
}

void    line_string_insert(t_line *line, const char *str, int size, t_cursor *cursor)
{
	if (line->len + size > line->size)
		line_resize(line, line->len + size + line->size * RATIO, line->size);
	if (cursor->col < line->len)
		memmove(line->buf + cursor->col + size, line->buf + cursor->col, size);
	memcpy(line->buf + cursor->col, str, size);
	cursor->col += size;
	line->len += size;
}

void    matrix_resize(t_matrix *matrix, int new_size, int old_size)
{
	matrix->lines = (t_line **)xrealloc(matrix->lines,
			sizeof(t_line *) * new_size, sizeof(t_line *) * old_size);
	matrix->size = new_size;
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
	while (i < size && matrix->right_limit < matrix->len - 1)
	{
		matrix->right_limit++;
		i += ((matrix->lines[matrix->right_limit]->symbols +
				get_line_prompt_len(matrix) - 1)/ g_w.ws_col + 1) * g_w.ws_col;
	}
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
	while (i < size && matrix->left_limit)
	{
		matrix->left_limit--;
		i += ((matrix->lines[matrix->left_limit]->symbols +
		      get_line_prompt_len(matrix) - 1)/ g_w.ws_col + 1) * g_w.ws_col;
	}
}

void check_limits(t_matrix *matrix)
{
	if (matrix->cursor->row < matrix->left_limit)
		change_limits_left_case(matrix, matrix->cursor->row);
	if (matrix->cursor->row > matrix->right_limit)
		change_limits_right_case(matrix, matrix->cursor->row);
}

void print_text(t_matrix *matrix, int row, int col)
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
					+ get_line_prompt_len(matrix)) / g_w.ws_col;
	}
	array_add(matrix->lines[left]->buf, col);
	array_flush();
}

void print_cursor(t_matrix *matrix)
{
	print_text(matrix, matrix->cursor->row, matrix->cursor->col);
}

void print_lines(t_matrix *matrix)
{
	print_text(matrix, matrix->right_limit, matrix->lines[matrix->right_limit]->len);
}

void print_default(t_matrix *matrix)
{
	add_offset(matrix->last_offset);
	array_add(CURSOR_CLEAR_TO_END_SCREEN, 0);
	print_lines(matrix);
	add_offset(matrix->last_offset);
	print_cursor(matrix);
}

void    auto_complete(t_matrix *matrix)
{
	add_offset(matrix->last_offset);
	print_lines(matrix);
	if (matrix)
		ft_puts ("\nmain.c  readline.c  array.c\n", 0);
	print_prompt();
}

int     readline_mode(t_matrix *matrix, char *str, t_uchar c)
{
	if (c == '\t' && g_comb[2] == 22)
	{
		auto_complete(matrix);
		print_lines(matrix);
		return (1);
	}
	if (c == '\n')
	{
		if (g_comb[2] != '\\')
		{
			if (matrix->lines[matrix->right_limit]->len != 0)
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
	check_limits(matrix);
	print_default(matrix);
	return (1);
}

int check_buttons(t_matrix *matrix, t_uchar c)
{
	(void)matrix;
	(void)c;
	return (0);
}

int check_esc_code(t_matrix *matrix)
{
	int i;
	time_t start;
	time_t end;
	t_uchar c;
	t_uchar tmp;

	i = 0;
	c = 27;
	while (i < 8)
	{
		start = clock();
		tmp = get_next_symbol(sizeof(char));
		end = clock();
		if (end - start > 0)
		{
			g_mode = VI;
			return (1);
		}
		c = (c << 8) + tmp;
		if (check_buttons(matrix, c))
			return (1);
		i++;
	}
	g_mode = VI;
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

int     readline(t_matrix *matrix)
{
	int     ret;
	get_term_params(&g_w);
	print_prompt();
	print_lines(matrix);
	ret = 1;
	while (ret > 0)
		ret = check_next_symbol(matrix);
	if (ret == -1)
	{
		return (0);
/*		if check no leaks need to call exit here*/
/*		exit(0);*/
	}
	return (1);
}