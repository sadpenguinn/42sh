/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:01:20 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 17:02:40 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "array.h"
#include "libshell.h"

int		print_default(t_matrix *matrix)
{
	set_matrix_limits(matrix);
	add_cursor_offset(matrix->last_offset);
	array_add(CURSOR_CLEAR_TO_END_SCREEN, strlen(CURSOR_CLEAR_TO_END_SCREEN));
	add_lines_text(matrix);
	add_cursor_offset(matrix->last_offset);
	add_cursor_text(matrix);
	array_flush();
	return (1);
}

int		print_lines(t_matrix *matrix)
{
	set_matrix_limits(matrix);
	add_cursor_offset(matrix->last_offset);
	array_add(CURSOR_CLEAR_TO_END_SCREEN, strlen(CURSOR_CLEAR_TO_END_SCREEN));
	add_lines_text(matrix);
	array_flush();
	return (1);
}

char	*get_pattern_rel_dir(t_matrix *matrix, int *col)
{
	t_line	*line;
	char 	*pattern;

	line = matrix->lines[matrix->cursor->row];
	*col = matrix->cursor->col;
	while (*col && line->buf[*col] != ' ' && line->buf[*col] != '/')
		(*col)--;
	if (line->buf[*col] == ' ' || line->buf[*col] == '/')
		(*col)++;
	pattern = ft_strndup(line->buf + *col, matrix->cursor->col - *col);
	pattern = ft_strjoin(pattern, "*", 1);
	return (pattern);
}

char 	*get_rel_dir(t_matrix *matrix)
{
	t_line	*line;
	int 	col1;
	int 	col2;

	line = matrix->lines[matrix->cursor->row];
	col2 = matrix->cursor->col;
	while (col2 && line->buf[col2] != '/' && line->buf[col2] != ' ')
		col2--;
	if (line->buf[col2] == '/')
		col2++;
	col1 = col2;
	while (col1 && line->buf[col1] != ' ')
		col1--;
	if (line->buf[col1] == ' ')
		col1++;
	if (col1 >= col2)
		return (ft_strdup("."));
	return (ft_strndup(line->buf + col1, col2 - col1));
}

char 	*get_string_to_insert(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (s2);
}

int		print_autocomplete_dir(t_matrix *matrix)
{
	char	**matches;
	size_t	cnt;
	size_t 	i;
	char 	*pattern;
	char 	*dir;
	int 	col;
	t_line	*line;

	matches = NULL;
	dir = get_rel_dir(matrix);
	pattern = get_pattern_rel_dir(matrix, &col);
	xglob(pattern, dir, &matches, &cnt);
	line = matrix->lines[matrix->cursor->row];
	if (cnt > 1)
	{
		set_matrix_limits(matrix);
		add_cursor_offset(matrix->last_offset);
		add_lines_text(matrix);
		i = 0;
		array_add("\n", 1);
		while (i < cnt)
		{
			array_add(matches[i], strlen(matches[i]));
			array_add("\n", 1);
			i++;
		}
		print_prompt();
		matrix->last_offset = 0;
	}
	if (cnt == 1)
	{
		free(pattern);
		pattern = ft_strjoin(get_string_to_insert(line->buf + col, matches[0]), " ", 0);
		matrix_string_insert(matrix, matrix->cursor, pattern, strlen(pattern));
	}
	free(pattern);
	free(dir);
	return (1);
}

int		print_autocomplete(t_matrix *matrix)
{
	return (print_autocomplete_dir(matrix));
}
