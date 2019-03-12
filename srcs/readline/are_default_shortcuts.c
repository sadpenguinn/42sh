/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_default_shortcuts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:47:45 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:34:04 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int			are_default_shortcuts(t_matrix *matrix, t_uchar c)
{
	if (c == CTRL_B || c == LEFT)
		return (move_cursor_left(matrix));
	if (c == CTRL_F || c == RIGHT)
		return (move_cursor_right(matrix));
	if (c == HOME1 || c == HOME2)
		return (move_cursor_home(matrix));
	if (c == END1 || c == END2)
		return (move_cursor_end(matrix));
	if (c == DEL)
		return (del(matrix));
	if (c == CTRL_P)
		return (move_history_prev());
	if (c == CTRL_N)
		return (move_history_next());
	if (c == UP)
		return (move_cursor_up(matrix));
	if (c == DOWN)
		return (move_cursor_down(matrix));
	if (c == CTRL_H)
		return (move_cursor_begin_word(matrix));
	if (c == CTRL_L)
		return (move_cursor_end_word(matrix));
	return (0);
}

static int	are_default_normal_mode_basic_shortcuts(t_matrix *matrix, t_uchar c)
{
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
	if (c == 'h')
		return (move_cursor_left(matrix));
	if (c == 'l')
		return (move_cursor_right(matrix));
	if (c == 'k')
		return (move_cursor_up(matrix));
	if (c == 'j')
		return (move_cursor_down(matrix));
	if (c == '$')
		return (move_cursor_end(matrix));
	if (c == '^')
		return (move_cursor_begin(matrix));
	return (0);
}

static int	are_default_normal_mode_advanced_shortcuts(t_matrix *matrix,
		t_uchar c)
{
	if (c == '|' || c == '0')
		return (move_cursor_home(matrix));
	if (c == 'x')
		return (del(matrix));
	if (c == 'X')
		return (back_space(matrix));
	if (c == 'D')
		return (del_end(matrix));
	if (c == 'Y')
		return (yank_string(matrix));
	if (c == BS)
		return (move_cursor_left(matrix));
	if (c == 'p')
		return (paste_after(matrix));
	if (c == 'P')
		return (paste_before(matrix));
	if (c == 'R')
	{
		g_vi_mode = REPLACE_MODE;
		return (1);
	}
	return (0);
}

int			are_default_normal_mode_shortcuts(t_matrix *matrix, t_uchar c)
{
	if (are_default_normal_mode_basic_shortcuts(matrix, c))
		return (1);
	return (are_default_normal_mode_advanced_shortcuts(matrix, c));
}
