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

static int	vi_mode_normal_del_basic(t_matrix *matrix, t_uchar c)
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
	if (c == '$' || c == END1 || c == END2)
		return (del_end(matrix));
	if (c == '|' || c == '0' || c == HOME1 || c == HOME2)
		return (del_home(matrix));
	if (c == '^')
		return (del_begin(matrix));
	if (c == 'd')
	{
		g_shortcuts[SHORTCUT_ARRAY_SIZE - 1] = 0;
		return (del_string(matrix));
	}
	return (0);
}

static int	vi_mode_normal_del_advanced(t_matrix *matrix, t_uchar c)
{
	matrix = NULL;
	c = 0;
	return (0);
}

int	vi_mode_normal_del(t_matrix *matrix, t_uchar c)
{
	if (vi_mode_normal_del_basic(matrix, c))
		return (1);
	if (vi_mode_normal_del_advanced(matrix, c))
		return (1);
	return (1);
}
