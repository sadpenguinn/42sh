/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:35:54 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/14 16:40:16 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		find_pos_left(const char *buf, int pos)
{
	if (pos != 0)
	{
		if ((buf[pos - 1] >> 7) & 1)
			while (pos > 1 && ((buf[pos - 1] >> 6) & 1) == 0)
				pos--;
		pos--;
	}
	return (pos);
}

int		find_pos_right(const char *buf, int len, int pos)
{
	if (pos != len)
	{
		if ((buf[(pos)++] >> 7) & 1)
			while (pos != len && ((buf[pos] >> 7) & 1) && (((buf[pos] >> 6) & 1) == 0))
				pos++;
	}
	return (pos);
}
