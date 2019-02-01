/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pos_functions_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 09:49:48 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/17 09:51:24 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

static int	is_alnum_symbol(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int			move_pos_next_alnum(char *buf, int len, int *pos)
{
	int		i;

	i = 0;
	while (*pos < len && is_alnum_symbol(buf[*pos]))
	{
		*pos = find_pos_right(buf, len, *pos);
		i++;
	}
	while (*pos < len && !is_alnum_symbol(buf[*pos]))
	{
		*pos = find_pos_right(buf, len, *pos);
		i++;
	}
	return (i);
}

int			move_pos_back_alnum(char *buf, int len, int *pos)
{
	int		i;

	i = 0;
	if (*pos > 0)
	{
		*pos = find_pos_left(buf, *pos);
		i++;
	}
	while (*pos > 0 && !is_alnum_symbol(buf[*pos]))
	{
		*pos = find_pos_left(buf, *pos);
		i++;
	}
	while (*pos > 0 && is_alnum_symbol(buf[*pos]))
	{
		*pos = find_pos_left(buf, *pos);
		i++;
	}
	if (*pos > 0)
		*pos = find_pos_right(buf, len, *pos);
	else
		i++;
	return (i - 1);
}
