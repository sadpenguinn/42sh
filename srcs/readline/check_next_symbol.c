/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_symbol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:46:57 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/03 20:34:18 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <unistd.h>
#include <string.h>

static int	is_utf(char c)
{
	if ((c >> 7) & 1)
		return (1);
	return (0);
}

static int	utf_handling(t_uchar c)
{
	t_uchar tmp;

	tmp = get_next_symbol(get_utf_offset_right(c));
	c += (tmp << 8);
	return (modes_handling(g_history->cur_matrix, c));
}

int			check_next_symbol(void)
{
	t_uchar	c;

	c = get_next_symbol(sizeof(char));
	if (c == CTRL_D)
		return (-1);
	if (c == ESC)
		return (esc_code_handling(c));
	if (is_utf(c))
		return (utf_handling(c));
	return (modes_handling(g_history->cur_matrix, c));
}
