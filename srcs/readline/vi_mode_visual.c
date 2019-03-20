/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_mode_visual.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:19:04 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/20 15:19:05 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

static int	are_default_vi_mode_visual_shortcuts(t_matrix *matrix, t_uchar c)
{
	if (c == CTRL_B || c == LEFT || c == BS || c == 'h')
		return (move_cursor_left(matrix));
	if (c == CTRL_F || c == RIGHT || c == 'l')
		return (move_cursor_right(matrix));
	if (c == HOME1 || c == HOME2 || c == '0' || c == '|')
		return (move_cursor_home(matrix));
	if (c == END1 || c == END2 || c == '$')
		return (move_cursor_end(matrix));
	if (c == '^')
		return (move_cursor_begin(matrix));
	if (c == 'W')
		return (move_cursor_next_word(matrix));
	if (c == 'B')
		return (move_cursor_begin_word(matrix));
	if (c == 'E')
		return (move_cursor_end_word(matrix));
	if (c == 'w')
		return (move_cursor_next_alnum(matrix));
	if (c == 'b')
		return (move_cursor_begin_alnum(matrix));
	if (c == 'e')
		return (move_cursor_end_alnum(matrix));
	return (0);
}

static int	is_find_char(t_matrix *matrix, t_uchar c)
{
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'f')
	{
		g_history->find_char = (char)c;
		g_history->prev_find_option = 'f';
		return (move_cursor_next_char(matrix));
	}
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'F')
	{
		g_history->find_char = (char)c;
		g_history->prev_find_option = 'F';
		return (move_cursor_back_char(matrix));
	}
	if (c == ';')
		return (move_cursor_find_char_reverse_order(matrix));
	if (c == ',')
		return (move_cursor_find_char_usual_order(matrix));
	return (0);
}

static int	is_insert_mode(t_matrix *matrix, t_uchar c)
{
	t_cursor	point1;
	t_cursor	point2;

	g_vi_mode = INSERT_MODE;
	if (c == 'c' || c == 's')
	{
		set_points(&point1, &point2);
		*matrix->cursor = matrix_string_delete(point1, point2);
		return (1);
	}
	if (c == 'I')
		return (move_cursor_home(matrix));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'c')
		return (vi_mode_normal_del(matrix, c));
	if (c == 'A')
		return (1);
	if (c == 'S' || c == 'R' || c == 'C')
		return (del_string(matrix));
	g_vi_mode = VISUAL_MODE;
	return (0);
}

int			vi_mode_visual(t_matrix *matrix, t_uchar c)
{
	if (c == ESC)
	{
		g_vi_mode = NORMAL_MODE;
		return (1);
	}
	if (is_find_char(matrix, c))
		return (1);
	if (are_default_vi_mode_visual_shortcuts(matrix, c))
		return (1);
	if (vi_mode_visual_is_normal_mode(matrix, c))
		return (1);
	if (is_insert_mode(matrix, c))
		return (1);
	return (1);
}
