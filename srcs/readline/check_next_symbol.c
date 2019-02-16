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

#include <termios.h>
#include "readline.h"
#include <unistd.h>

t_uchar	get_next_symbol(void)
{
	unsigned char c;

	c = 0;
	int ret = read(1, &c, sizeof(char));
	if (ret == -1)
		return (0);
	return (c);
}

int check_utf(t_matrix *matrix, t_uchar c)
{
	t_uchar tmp;
	int i;
	int ret;

	tmp = 0;
	while (tmp == 0)
		tmp = get_next_symbol();
	i = 8;
	while (tmp && is_utf_suffix(tmp))
	{
		c += (tmp << i);
		tmp = get_next_symbol();
		i += 8;
	}
	comb_offset(c);
	ret = check_modes(matrix, c);
	if (tmp != 0)
		return (check_next_symbol(matrix, tmp));
	return (ret);
}

int check_next_symbol(t_matrix *matrix, t_uchar c)
{
	while (c == 0)
		c = get_next_symbol();
	if (c == CTRL_D)
		return (-1);
	if (c == 27)
		return (check_esc_code(matrix));
	if (is_utf(c))
		return (check_utf(matrix, c));
	comb_offset(c);
	return (check_modes(matrix, c));
}
