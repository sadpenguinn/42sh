/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_mode_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:40:10 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:40:22 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

static int	is_insert_mode(t_matrix *matrix, t_uchar c)
{
	g_vi_mode = INSERT_MODE;
	if (c == 'i')
		return (1);
	if (c == 'I')
		return (move_cursor_home(matrix));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'c')
		return (vi_mode_normal_del(matrix, c));
	if (c == 'C')
		return (del_end(matrix));
	if (c == 'a')
		return (move_cursor_right(matrix));
	if (c == 'A')
		return (move_cursor_end(matrix));
	if (c == 's')
		return (del_symbol(matrix));
	if (c == 'S')
		return (del_string(matrix));
	g_vi_mode = NORMAL_MODE;
	return (0);
}

static int	is_find_char(t_matrix *matrix, t_uchar c)
{
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'f')
	{
		g_history->find_char = (char)c;
		g_history->prev_find_option = 'f';
		if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 3] == 'd')
			return (vi_mode_normal_del(matrix, c));
		if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 3] == 'y')
			return (vi_mode_normal_yank(matrix, c));
		return (move_cursor_next_char(matrix));
	}
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'F')
	{
		g_history->find_char = (char)c;
		g_history->prev_find_option = 'F';
		if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 3] == 'd')
			return (vi_mode_normal_del(matrix, c));
		if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 3] == 'y')
			return (vi_mode_normal_yank(matrix, c));
		return (move_cursor_back_char(matrix));
	}
	if (c == ';')
		return (move_cursor_find_char_reverse_order(matrix));
	if (c == ',')
		return (move_cursor_find_char_usual_order(matrix));
	return (0);
}

static int	replace_symbol(t_matrix *matrix, t_uchar c)
{
	char	str[sizeof(t_uchar)];

	if (c == LEFT || c == RIGHT ||
		c == DOWN || c == UP ||
		c == HOME1 || c == HOME2 ||
		c == END1 || c == END2 ||
		c == DEL || c == BS)
		return (1);
	del_symbol(matrix);
	ft_memset(str, 0, sizeof(t_uchar));
	*matrix->cursor = matrix_string_insert(matrix, *matrix->cursor,
			str, symbol_to_string(c, str));
	matrix->cursor->col = get_cursor_pos_left(matrix);
	g_shortcuts[SHORTCUT_ARRAY_SIZE - 1] = 0;
	return (1);
}

int			vi_mode_normal(t_matrix *matrix, t_uchar c)
{
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'd')
		return (vi_mode_normal_del(matrix, c));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'y')
		return (vi_mode_normal_yank(matrix, c));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'r')
		return (replace_symbol(matrix, c));
	if (is_find_char(matrix, c))
		return (1);
	if (is_insert_mode(matrix, c))
		return (1);
	if (are_default_vi_normal_mode_shortcuts(matrix, c))
		return (1);
	if (c == '\n')
		return (newline_handling(matrix));
	if (c == 'v')
	{
		matrix->point = *matrix->cursor;
		g_vi_mode = VISUAL_MODE;
		return (1);
	}
	return (1);
}
