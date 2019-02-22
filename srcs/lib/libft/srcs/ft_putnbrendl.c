/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:08:22 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbrendl(int n)
{
	long	ln;
	long	pos;

	pos = 1;
	ln = (long)n;
	if (ln < 0)
	{
		write(1, "-", 1);
		ln = -ln;
	}
	while ((ln / (pos * 10)) > 0)
		pos = pos * 10;
	while (pos > 0)
	{
		ft_putchar((ln / pos) + '0');
		ln = ln % pos;
		pos = pos / 10;
	}
	write(1, "\n", 1);
}
