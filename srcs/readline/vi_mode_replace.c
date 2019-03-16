/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_mode_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:28:11 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:28:23 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

static int	are_default_vi_mode_replace_shortcuts(t_matrix *matrix, t_uchar c)
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
		return (del_symbol(matrix));
	if (c == CTRL_P)
		return (move_history_prev());
	if (c == CTRL_N)
		return (move_history_next());
	if (c == UP)
		return (move_cursor_up(matrix));
	if (c == DOWN)
		return (move_cursor_down(matrix));
	if (c == BS)
		return (back_space(matrix));
	return (0);
}

int	vi_mode_replace(t_matrix *matrix, t_uchar c)
{
	char	str[sizeof(t_uchar)];

	if (c == CTRL_R)
	{
		g_search_mode = 1;
		return (1);
	}
	if (are_default_vi_mode_replace_shortcuts(matrix, c))
		return (1);
	if (c == '\t' && g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] != CTRL_V)
		return (print_autocomplete(matrix));
	if (c == '\n')
		return (newline_handling(matrix));
	if (c == ESC)
	{
		g_vi_mode = NORMAL_MODE;
		return (1);
	}
	del_symbol(matrix);
	ft_memset(str, 0, sizeof(t_uchar));
	*matrix->cursor = matrix_string_insert(matrix, *matrix->cursor,
			str, symbol_to_string(c, str));
	return (1);
}
