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

static int	check_utf(t_matrix *matrix, t_uchar c)
{
	t_uchar tmp;

	tmp = get_next_symbol(get_utf_offset_right(c));
	c += (tmp << 8);
	return (check_modes(matrix, c));
}

int			check_next_symbol(t_matrix *matrix)
{
	t_uchar	c;

	c = get_next_symbol(sizeof(char));
	if (c == CTRL_D)
		return (-1);
	if (c == ESC)
		return (check_esc_code(matrix, c));
	else if (is_utf(c))
		return (check_utf(matrix, c));
	else
		return (check_modes(matrix, c));
}
