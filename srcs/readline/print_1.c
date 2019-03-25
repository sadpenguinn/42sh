/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:17:00 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/20 15:17:19 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "../lib/libshell/includes/libshell.h"

int			print_default(t_matrix *matrix)
{
	set_matrix_limits(matrix);
	add_cursor_offset();
	array_add(CURSOR_CLEAR_TO_END_SCREEN,
			ft_strlen(CURSOR_CLEAR_TO_END_SCREEN));
	add_lines_text(matrix);
	add_cursor_offset();
	add_cursor_text(matrix);
	array_flush();
	return (1);
}

int			print_end(t_matrix *matrix)
{
	set_matrix_limits(matrix);
	add_cursor_offset();
	array_add(CURSOR_CLEAR_TO_END_SCREEN,
			ft_strlen(CURSOR_CLEAR_TO_END_SCREEN));
	add_lines_text(matrix);
	array_add("\n", 1);
	array_flush();
	return (1);
}

int			print_search(t_matrix *matrix)
{
	t_line	*line;
	size_t	symbols;

	set_matrix_limits(matrix);
	add_cursor_offset();
	array_add(CURSOR_CLEAR_TO_END_SCREEN,
			ft_strlen(CURSOR_CLEAR_TO_END_SCREEN));
	add_lines_text(matrix);
	array_add("\n", 1);
	line = g_history->search_line;
	array_add(SEARCH_PROMPT, ft_strlen(SEARCH_PROMPT));
	add_line(line, 0, line->len, 0);
	symbols = line->symbols + ft_strlen(SEARCH_PROMPT);
	g_history->last_offset += 1 + symbols / g_w.ws_col;
	if (symbols % g_w.ws_col == 0)
		array_add("\n", 1);
	array_flush();
	return (1);
}

int			print_event_message(void)
{
	array_add(SHELL_NAME, ft_strlen(SHELL_NAME));
	array_add(": ", 2);
	array_add(EVENT_MESSAGE, ft_strlen(EVENT_MESSAGE));
	array_add(": ", 2);
	array_add(g_history->event->buf, g_history->event->len);
	array_add("\n", 1);
	array_flush();
	return (1);
}
