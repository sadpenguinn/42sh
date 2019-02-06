/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pos_functions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 09:49:30 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/17 09:52:30 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

static int	is_space_symbol(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int			move_pos_next_word(char *buf, int len, int *pos)
{
	int		i;

	i = 0;
	while (*pos < len && !is_space_symbol(buf[*pos]))
	{
		*pos = find_pos_right(buf, len, *pos);
		i++;
	}
	while (*pos < len && is_space_symbol(buf[*pos]))
	{
		*pos = find_pos_right(buf, len, *pos);
		i++;
	}
	return (i);
}

int			move_pos_back_word(char *buf, int len, int *pos)
{
	int		i;

	i = 0;
	if (*pos > 0)
	{
		*pos = find_pos_left(buf, *pos);
		i++;
	}
	while (*pos > 0 && is_space_symbol(buf[*pos]))
	{
		*pos = find_pos_left(buf, *pos);
		i++;
	}
	while (*pos > 0 && !is_space_symbol(buf[*pos]))
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
