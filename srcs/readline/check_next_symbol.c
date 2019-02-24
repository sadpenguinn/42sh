/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_symbol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:10:56 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/24 16:45:06 by sitlcead         ###   ########.fr       */
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

static int	check_modes(t_matrix *matrix, t_uchar c)
{
	move_shortcuts(c);
	if (g_mode == READLINE)
		return (readline_mode(matrix, c));
	if (g_mode == VI)
		return (readline_mode(matrix, c));
	return (1);
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
