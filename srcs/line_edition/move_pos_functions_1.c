/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pos_functions_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 09:12:47 by sitlcead          #+#    #+#             */
/*   Updated: 2019/01/15 16:37:20 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		move_pos_left(char *buf, int *len, int *pos)
{
	if (*pos == 0)
		return (0);
	*pos = find_pos_left(buf, *pos);
	return (1);
}

int		move_pos_right(char *buf, int *len, int *pos)
{
	if (*pos == *len)
		return (0);
	*pos = find_pos_right(buf, *len, *pos);
	return (1);
}

int		move_pos_begin(char *buf, int *len, int *pos)
{
	int		i;

	i = 0;
	while (*pos != 0)
	{
		*pos = find_pos_left(buf, *pos);
		i++;
	}
	return (i);
}

int		move_pos_end(char *buf, int *len, int *pos)
{
	int		i;

	i = 0;
	while (*pos != *len)
	{
		*pos = find_pos_right(buf, *len, *pos);
		i++;
	}
	return (i);
}
