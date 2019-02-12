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

static t_uchar	ft_getchar()
{
	t_uchar	c;

	c = 0;
	read(1, &c, sizeof(t_uchar));
	return (c);
}

t_uchar	get_next_symbol(void)
{
	struct termios	old;
	struct termios	new;
	t_uchar			c;

	tcgetattr(0, &old);
	new = old;
	new.c_lflag &= ~(ICANON | ECHO);
/*	new.c_lflag &= ~(ICANON);*/
    new.c_cc[VLNEXT] = 026;
    new.c_cc[VEOF] = 04;
    new.c_cc[VREPRINT] = 022;
	new.c_cc[VQUIT] = 034;
	tcsetattr(0, TCSANOW, &new);
	c = ft_getchar();
	tcsetattr(0, TCSANOW, &old);
	return (c);
}
