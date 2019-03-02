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
int		print_autocomplete(t_matrix *matrix)
{
	return (autocomplete_file_dir(matrix));
}
