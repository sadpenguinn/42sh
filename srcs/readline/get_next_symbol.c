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
	t_uchar c;

	c = 0;
	read(1, &c, sizeof(t_uchar));
	return (c);
}
