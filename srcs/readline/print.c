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
#include "libshell.h"
#include "autocomplete.h"

int		print_default(t_matrix *matrix)
{
	set_matrix_limits(matrix);
	add_cursor_offset(g_history->last_offset);
	array_add(CURSOR_CLEAR_TO_END_SCREEN, strlen(CURSOR_CLEAR_TO_END_SCREEN));
	add_lines_text(matrix);
	add_cursor_offset(g_history->last_offset);
	add_cursor_text(matrix);
	array_flush();
	return (1);
}

int		print_lines(t_matrix *matrix)
{
	set_matrix_limits(matrix);
	add_cursor_offset(g_history->last_offset);
	array_add(CURSOR_CLEAR_TO_END_SCREEN, strlen(CURSOR_CLEAR_TO_END_SCREEN));
	add_lines_text(matrix);
	array_flush();
	return (1);

}

static int print_possibilities(t_matrix *matrix, char **matches, size_t cnt)
{
	size_t	i;

	set_matrix_limits(matrix);
	add_cursor_offset(g_history->last_offset);
	add_lines_text(matrix);
	i = 0;
	array_add("\n", 1);
	while (i < cnt)
	{
		array_add(matches[i], strlen(matches[i]));
		free(matches[i]);
		array_add("\n", 1);
		i++;
	}
	print_prompt();
	g_history->last_offset = 0;
	free(matches);
	return (1);
}

int		print_autocomplete(t_matrix *matrix)
{
	char	**matches;
	size_t	cnt;

	matches = autocomplete(matrix->lines[matrix->cursor->row], matrix->cursor->col);
	if (matches == NULL)
		return (1);
	cnt = 0;
	while (matches[cnt])
		cnt++;
	if (cnt > 1)
		return print_possibilities(matrix, matches, cnt);
	*matrix->cursor = matrix_string_insert(matrix, *matrix->cursor, matches[0], strlen(matches[0]));
	return (1);
}
