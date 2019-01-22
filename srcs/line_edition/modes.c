/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 23:24:09 by sitlcead          #+#    #+#             */
/*   Updated: 2019/01/22 14:03:12 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

long long int		g_vim_keys[] =
{
	'w', 'W',
	'B', 'b',
	'I', 'i',
	'A', 'a',
	'h', 'l',
	'^', '$',
	HOME1, HOME2,
	END1, END2,
	LEFT, RIGHT,
	BS, DEL,
	'x',
	0
};

int	normal_mode(char *buf, int *len, int *pos, t_uchar c)
{
	if (c == LEFT || c == BS || c == 'h')
		move_cursor_left(move_pos_left(buf, len, pos));
	if (c == RIGHT || c == 'l' || c == 'a')
		move_cursor_right(move_pos_right(buf, len, pos));
	if (c == HOME1 || c == HOME2 || c == '^' || c == 'I')
		move_cursor_left(move_pos_begin(buf, len, pos));
	if (c == END1 || c == END2 || c == '$' || c =='A')
		move_cursor_right(move_pos_end(buf, len, pos));
	if (c == 'w')
		move_cursor_right(move_pos_next_alnum(buf, *len, pos));
	if (c == 'b')
		move_cursor_left(move_pos_back_alnum(buf, *len, pos));
	if (c == 'W')
		move_cursor_right(move_pos_next_word(buf, *len, pos));
	if (c == 'B')
		move_cursor_left(move_pos_back_word(buf, *len, pos));
	if (c == 'v')
		g_mode = VISUAL_MODE;
	if (c == 'i' || c == 'a' || c == 'I' || c == 'A')
		g_mode = INSERT_MODE;
	return (1);
}

static int	check_normal_mode(char *buf, int *len, int *pos, t_uchar c)
{
	int	i;

	i = -1;
	if (c == ESC)
	{
		g_mode = NORMAL_MODE;
		return (1);
	}
	while (g_vim_keys[++i])
	{
		if (g_vim_keys[i] * 16 * 16 + ESC == c)
		{
			g_mode = NORMAL_MODE;
			return (normal_mode(buf, len, pos, g_vim_keys[i]));
		}
	}
	if (g_mode == NORMAL_MODE)
		return (normal_mode(buf, len, pos, c));
	return (0);
}

static int	insert_mode(char *buf, int *len, int *pos, t_uchar c)
{
	if (c == LEFT)
		return (move_cursor_left(move_pos_left(buf, len, pos)));
	if (c == RIGHT)
		return (move_cursor_right(move_pos_right(buf, len, pos)));
	if (c == HOME1 || c == HOME2)
		return (move_cursor_left(move_pos_begin(buf, len, pos)));
	if (c == END1 || c == END2)
		return (move_cursor_right(move_pos_end(buf, len, pos)));
	if (check_normal_mode(buf, len, pos, c))
		return (1);
	clear_line(buf, len, pos);
	simple_line_edition(buf, len, pos, c);
	output_line(buf, len, pos);
	return (1);
}

static int	visual_mode(char *buf, int *len, int *pos, t_uchar c)
{
	if (c == ESC)
	{
		g_mode = NORMAL_MODE;
		return (1);
	}
	return (1);
}

int			check_modes(char *buf, int *len, int *pos, t_uchar c)
{
	if (g_mode == INSERT_MODE)
		return (insert_mode(buf, len, pos, c));
	if (g_mode == VISUAL_MODE)
		return (visual_mode(buf, len, pos, c));
	if (check_normal_mode(buf, len, pos, c))
		return (1);
	return (1);
}
