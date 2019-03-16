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

static int	vi_mode_normal_yank_basic(t_matrix *matrix, t_uchar c)
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
	if (c == '$' || c == END1 || c == END2)
		return (yank_end(matrix));
	if (c == '|' || c == '0' || c == HOME1 || c == HOME2)
		return (yank_home(matrix));
	if (c == '^')
		return (yank_begin(matrix));
	if (c == 'y')
	{
		g_shortcuts[SHORTCUT_ARRAY_SIZE - 1] = 0;
		return (yank_string(matrix));
	}
	return (0);
}

static int	vi_mode_normal_yank_advanced(t_matrix *matrix, t_uchar c)
{
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'f')
		return (yank_find_next_char(matrix));
	if (g_shortcuts[SHORTCUT_ARRAY_SIZE - 2] == 'F')
		return (yank_find_back_char(matrix));
	if (c == ';')
		return (yank_find_char_reverse_order(matrix));
	if (c == ',')
		return (yank_find_char_usual_order(matrix));
	return (0);
}

int	vi_mode_normal_yank(t_matrix *matrix, t_uchar c)
{
	if (vi_mode_normal_yank_advanced(matrix, c))
		return (1);
	if (vi_mode_normal_yank_basic(matrix, c))
		return (1);
	return (1);
}
