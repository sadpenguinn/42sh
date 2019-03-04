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
#include "time.h"

static int	check_esc_buttons(t_uchar c)
{
	if (c == LEFT || c == RIGHT ||
			c == DOWN || c == UP ||
			c == HOME1 || c == HOME2 ||
			c == END1 || c == END2 ||
			c == DEL)
		return (1);
	return (0);
}

int			check_esc_code(t_matrix *matrix, t_uchar c)
{
	int		i;
	time_t	start;
	time_t	end;
	t_uchar	tmp;
	int 	size;

	i = 0;
	size = sizeof(t_uchar);
	while (++i < size)
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
		if (check_esc_buttons(c))
			return (check_modes(matrix, c));
	}
	if (g_mode == VI)
		check_modes(matrix, ESC);
	return (1);
}
