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

int	normal_mode_yank(t_matrix *matrix, t_uchar c)
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
