/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pos_functions_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 09:12:47 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/01 13:38:47 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		move_pos_left(char *buf, int *len, int *pos)
{
	if (*pos == 0)
		return (0);
	/* if (buf[*pos - 1] == '\t') */
	/* 	write(1, "\e[1Z", 4); */
	/* else */
	/* 	move_cursor_left(1); */
	*pos = find_pos_left(buf, *pos);
	return (1);
}

int		move_pos_right(char *buf, int *len, int *pos)
{
	if (*pos == *len)
		return (0);
	/* if (buf[*pos] == '\t') */
	/* 	write(1, "\t", 1); */
	/* else */
	/* 	move_cursor_right(1); */
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
