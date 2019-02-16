/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_symbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 23:34:11 by sitlcead          #+#    #+#             */
/*   Updated: 2019/01/14 14:49:24 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <unistd.h>
#include <string.h>

t_uchar	get_next_symbol(size_t size)
{
	t_uchar c;

	c = 0;
	if (size > sizeof(t_uchar))
		size = sizeof(t_uchar);
	read(0, &c, size);
	return (c);
}

static int is_utf(char c)
{
	if ((c >> 7) & 1)
		return (1);
	return (0);
}

int check_utf(t_matrix *matrix, t_uchar c)
{
	t_uchar tmp;
	int i;

	i = 0;
	while (i < 7 && ((c >> (6 - i)) & 1))
		i++;
	tmp = get_next_symbol(i);
	c += (tmp << 8);
	comb_offset(c);
	return (check_modes(matrix, c));
}

int check_next_symbol(t_matrix *matrix)
{
	t_uchar c;

	c = get_next_symbol(sizeof(char));
	if (c == CTRL_D)
		return (-1);
	if (c == 27)
		return (check_esc_code(matrix));
	if (is_utf(c))
		return (check_utf(matrix, c));
	comb_offset(c);
	return (check_modes(matrix, c));
}
