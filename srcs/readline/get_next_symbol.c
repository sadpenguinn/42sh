/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_symbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:49:52 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 16:50:13 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <unistd.h>

t_uchar		get_next_symbol(size_t size)
{
	t_uchar	c;

	c = 0;
	if (size > sizeof(t_uchar))
		size = sizeof(t_uchar);
	read(0, &c, size);
	return (c);
}
