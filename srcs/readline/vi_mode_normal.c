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

static int	normal_mode_del(t_matrix *matrix, t_uchar c)
{
	if (c == 'B')
		return (del_begin_word(matrix));
	if (c == 'W')
		return (del_next_word(matrix));
	if (c == 'E')
		return (del_end_word(matrix));
	if (c == 'b')
		return (del_begin_alnum(matrix));
	if (c == 'w')
		return (del_next_alnum(matrix));
	if (c == 'e')
		return (del_end_alnum(matrix));
	if (c == '$')
		return (del_end(matrix));
	if (c == '|' || c == '0')
		return (del_home(matrix));
	if (c == 'd')
	{
		g_shortcuts[SHORTCUT_ARRAY_SIZE - 1] = 0;
		return (del_string(matrix));
	}
	return (1);
}

static int	normal_mode_yank(t_matrix *matrix, t_uchar c)
{
	if (c == 'B')
		return (yank_begin_word(matrix));
	if (c == 'W')
		return (yank_next_word(matrix));
	if (c == 'E')
		return (yank_end_word(matrix));
	if (c == 'b')
		return (yank_begin_alnum(matrix));
	if (c == 'w')
		return (yank_next_alnum(matrix));
	if (c == 'e')
		return (yank_end_alnum(matrix));
	if (c == '$')
		return (yank_end(matrix));
	if (c == '|' || c == '0')
		return (yank_home(matrix));
	if (c == 'y')
	{
		g_shortcuts[SHORTCUT_ARRAY_SIZE - 1] = 0;
		return (yank_string(matrix));
	}
	return (1);
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
	if (c == CTRL_R)
	{
		g_search_mode = 1;
		return (1);
	}
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'd')
		return (normal_mode_del(matrix, c));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'y')
		return (normal_mode_yank(matrix, c));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'r')
		return (replace_symbol(matrix, c));
	if (is_insert_mode(matrix, c))
		return (1);
	if (are_default_shortcuts(matrix, c))
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
