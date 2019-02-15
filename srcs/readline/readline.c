#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "readline.h"
#include <unistd.h>
#include "term.h"
#include <stdio.h>
#include "shell.h"
#include "array.h"

t_uchar     g_comb[4];

int len;

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

void    auto_complete(char *line)
{
	(void)line;
}

void    line_resize(t_line *line, int new_size, int old_size)
{
	line->buf = (char *)xrealloc(line->buf, new_size + 1, old_size);
	line->size = new_size;
}

void    insert_string(t_line *line, const char *str, int size, t_cursor *cursor)
{
	if (line->len + size > line->size)
		line_resize(line, line->len + size + line->size * RATIO, line->size);
	if (cursor->col < len)
		memmove(line->buf + cursor->col + size, line->buf + cursor->col, size);
	memcpy(line->buf + cursor->col, str, size);
	cursor->col += size;
	line->len += size;
}

void    matrix_insert(t_matrix *matrix, const char *str)
{
	int j;
	int size;
	t_line *line;
	int cnt;

	line = matrix->line[matrix->cursor->row];
	j = 0;
	while (str[j] != 0)
	{
		size = 0;
		while (str[j] != '\n' && str[j])
		{
			j++;
			size++;
			cnt++;
		}
		insert_string(line, str, size, matrix->cursor);
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

void print_lines(t_matrix *matrix)
{
	array_add(CURSOR_MOVE_LINE_START, 0);
	array_add("1> ", 0);
	array_add(matrix->line[0]->buf, 0);
	array_flush();
}

int     check_next_symbol(t_matrix *matrix)
{
	t_uchar c;
	char tmp[9];

	memset(tmp, 0, 9);
	c = get_next_symbol();
	comb_offset(c);
//	printf("%lld\n", c);
	if (c == '\n')
		return (0);
	if (c == CTRL_D)
		return (-1);
	if (c == 22)
		return (1);
	if (c == '\t')
	{
		if (g_comb[2] == 22)
		{
			auto_complete("abc");
			return (1);
		}
	}
	make_string_from_symbol(tmp, c);
	matrix_insert(matrix, tmp);
	print_lines(matrix);
	return (1);
}

int     ft_readline(t_matrix *matrix)
{
	int     ret;
//	char    c;
	len = 0;

	print_prompt();
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