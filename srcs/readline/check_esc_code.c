/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_esc_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:53:30 by sitlcead          #+#    #+#             */
/*   Updated: 2019/03/03 20:45:34 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <time.h>

static int	check_esc_buttons(t_uchar c, int i)
{
	t_uchar	tmp;

	if (c == LEFT || c == RIGHT ||
		c == DOWN || c == UP ||
		c == HOME1 || c == HOME2 ||
		c == END1 || c == END2 ||
		c == DEL)
		return (1);
	tmp = 0;
	i += 2;
	while (--i)
		tmp = (tmp << 8) + 0xFF;
	c &= tmp;
	if (c == LEFT & tmp || c == RIGHT & tmp ||
		c == DOWN & tmp || c == UP & tmp ||
		c == HOME1 & tmp || c == HOME2 & tmp ||
		c == END1 & tmp || c == END2 & tmp ||
		c == DEL & tmp)
		return (2);
	return (0);
}

int			check_esc_code(t_matrix *matrix, t_uchar c)
{
	int		i;
	time_t	start;
	time_t	end;
	t_uchar	tmp;
	int		ret;

	i = 0;
	while (++i < sizeof(t_uchar))
	{
		start = time(&start);
		tmp = get_next_symbol(sizeof(char));
		end = time(&end);
		if (difftime(end, start) >= 1)
		{
			if (g_mode == VI)
				return (check_modes(matrix, ESC));
			return (1);
		}
		if (tmp == ESC)
		{
			if (g_mode == VI)
				check_modes(matrix, ESC);
			return (check_esc_code(matrix, ESC));
		}
		c += (tmp << (i * 8));
		ret = check_esc_buttons(c, i);
		if (ret == 1)
			return (check_modes(matrix, c));
		if (ret == 0)
		{
			if (g_mode == VI)
				check_modes(matrix, ESC);
			return (check_modes(matrix, c))
		}
	}
	if (g_mode == VI)
		check_modes(matrix, ESC);
	return (1);
}
