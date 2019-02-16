#include <fcntl.h>
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

void    matrix_string_insert(t_matrix *matrix, const char *str)
{
	int j;
	int size;
	t_line *line;
	int cnt;

	line = matrix->line[matrix->cursor->row];
	j = 0;
	while (str[j] != 0)
	{
		cnt = 0;
		size = 0;
		while (str[j] != '\n' && str[j])
		{
			j++;
			size++;
			cnt++;
		}
		line_string_insert(line, str, size, matrix->cursor);
		line->cnt += cnt;
	}
}

void    make_string_from_symbol(char *str, t_uchar c)
{
	int i;

	i = 0;
	if (c == '\t')
	{
		while (i < 4)
			str[i++] = ' ';
		return ;
	}
	str[i++] = (c & 0xFF);
	if ((c >> 8) & 0xFF)
		str[i++] = ((c >> 8) & 0xFF);
	if ((c >> 16) & 0xFF)
		str[i++] = ((c >> 16) & 0xFF);
	if ((c >> 24) & 0xFF)
		str[i++] = ((c >> 24) & 0xFF);
	if ((c >> 32) & 0xFF)
		str[i++] = ((c >> 32) & 0xFF);
	if ((c >> 40) & 0xFF)
		str[i++] = ((c >> 40) & 0xFF);
	if ((c >> 48) & 0xFF)
		str[i++] = ((c >> 48) & 0xFF);
	if ((c >> 56) & 0xFF)
		str[i++] = ((c >> 56) & 0xFF);
}

void    make_offset(t_matrix *matrix)
{
	int left = 0;
	int right = matrix->last_offset;
	while (left < right)
	{
		array_add(CSI "1A", 0);
		left++;
	}
	array_add(CURSOR_MOVE_LINE_START, 0);
	array_flush();
}

void print_lines(t_matrix *matrix)
{
	int left;
	int right;

	array_add(CURSOR_CLEAR_TO_END_SCREEN, 0);
	left = 0;
	right = matrix->len;
	matrix->last_offset = 0;
	while (left < right)
	{
		array_add("> ", 0);
		array_add(matrix->line[left]->buf, matrix->line[left]->len);
		left++;
		if (left != right)
		{
			matrix->last_offset++;
			array_add("\n", 1);
		}
	}
	array_flush();
}

void    auto_complete(t_matrix *matrix)
{
	make_offset(matrix);
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
	}
	if (c == '\n')
	{
		if (g_comb[2] != '\\')
		{
			if (matrix->line[matrix->len - 1]->len != 0)
				write(1, "\n", 1);
			return (0);
		}
		matrix->line[matrix->cursor->row]->len = matrix->cursor->col - 1;
		matrix->len++;
		matrix->line[matrix->len - 1] = init_line();
		matrix->cursor->row += 1;
		matrix->cursor->col = 0;
	}
	else
	{
		make_string_from_symbol(str, c);
		matrix_string_insert(matrix, str);
	}
	make_offset(matrix);
	print_lines(matrix);
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
		tmp = get_next_symbol();
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
	int flags = fcntl(0, F_GETFL, 0);
	fcntl(0, F_SETFL, flags | O_NONBLOCK);
	print_prompt();
	ret = 1;
	while (ret > 0)
		ret = check_next_symbol(matrix, 0);
	if (ret == -1)
	{
		return (0);
/*		if check no leaks need to call exit here*/
/*		exit(0);*/
	}
	return (1);
}