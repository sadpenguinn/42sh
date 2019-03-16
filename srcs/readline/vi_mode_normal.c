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
	if (c == 'h' || c == LEFT || c == CTRL_B || c == BS)
		return (move_cursor_left(matrix));
	if (c == 'l' || c == RIGHT || c == CTRL_F)
		return (move_cursor_right(matrix));
	if (c == 'k' || c == UP)
		return (move_cursor_up(matrix));
	if (c == 'j' || c == DOWN)
		return (move_cursor_down(matrix));
	if (c == '$' || c == END1 || c == END2)
		return (move_cursor_end(matrix));
	if (c == '^')
		return (move_cursor_begin(matrix));
	return (0);
}

static int	are_default_normal_mode_advanced_shortcuts(t_matrix *matrix,
														 t_uchar c)
{
	if (c == '|' || c == '0' || c == HOME1 || c == HOME2)
		return (move_cursor_home(matrix));
	if (c == 'x' || c == DEL)
		return (del(matrix));
	if (c == 'X')
		return (back_space(matrix));
	if (c == 'D')
		return (del_end(matrix));
	if (c == 'Y')
		return (yank_string(matrix));
	if (c == 'p')
		return (paste_after(matrix));
	if (c == 'P')
		return (paste_before(matrix));
	if (c == CTRL_P)
		return (move_history_prev());
	if (c == CTRL_N)
		return (move_history_next());
	if (c == 'R')
	{
		g_vi_mode = REPLACE_MODE;
		return (1);
	}
	return (0);
}

static int	are_default_normal_mode_shortcuts(t_matrix *matrix, t_uchar c)
{
	if (are_default_normal_mode_basic_shortcuts(matrix, c))
		return (1);
	return (are_default_normal_mode_advanced_shortcuts(matrix, c));
}

static int	is_insert_mode(t_matrix *matrix, t_uchar c)
{
	g_vi_mode = INSERT_MODE;
	if (c == 'i')
		return (1);
	if (c == 'I')
		return (move_cursor_home(matrix));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'c')
		return (normal_mode_del(matrix, c));
	if (c == 'C')
		return (del_end(matrix));
	if (c == 'a')
		return (move_cursor_right(matrix));
	if (c == 'A')
		return (move_cursor_end(matrix));
	if (c == 's')
		return (del(matrix));
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
		return (move_cursor_next_char(matrix));
	}
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'F')
	{
		g_history->find_char = (char)c;
		return (move_cursor_back_char(matrix));
	}
	if (c == ';')
		return (move_cursor_back_char(matrix));
	if (c == ',')
		return (move_cursor_next_char(matrix));
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
	del(matrix);
	ft_memset(str, 0, sizeof(t_uchar));
	*matrix->cursor = matrix_string_insert(matrix, *matrix->cursor,
			str, symbol_to_string(c, str));
	matrix->cursor->col = get_cursor_pos_left(matrix);
	g_shortcuts[SHORTCUT_ARRAY_SIZE - 1] = 0;
	return (1);
}

int			normal_mode(t_matrix *matrix, t_uchar c)
{
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'd')
		return (normal_mode_del(matrix, c));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'y')
		return (normal_mode_yank(matrix, c));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'r')
		return (replace_symbol(matrix, c));
	if (is_find_char(matrix, c))
		return (1);
	if (c == 'u')
		return (undo(matrix));
	if (c == CTRL_R)
		return (redo(matrix));
	if (is_insert_mode(matrix, c))
		return (1);
	if (are_default_normal_mode_shortcuts(matrix, c))
		return (1);
	if (c == '\n')
		return (newline_handling(matrix));
	if (c == 'v')
	{
		matrix->point = *matrix->cursor;
		g_vi_mode = VISUAL_MODE;
	}
	return (1);
}
