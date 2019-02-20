/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:23:49 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 10:41:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_size(int n)
{
	unsigned int	num;
	int				size;

	if (!n)
		return (1);
	size = n < 0 ? 1 : 0;
	num = n < 0 ? -n : n;
	n = 1000000000;
	while (!(num / n))
		n /= 10;
	while (n /= 10)
		size++;
	return (size + 1);
}

char		*ft_itoa(int n)
{
	char			*str;
	char			*rtn;
	unsigned int	num;

	if ((str = (char *)ft_strnew(sizeof(char) * ft_size(n))) == (char *)0)
		return ((char *)0);
	rtn = str;
	if (n < 0)
		*str++ = '-';
	num = n < 0 ? -n : n;
	if (!num)
		*str++ = '0';
	n = 1000000000;
	while (n && !(num / n))
		n /= 10;
	while (n)
	{
		*str++ = num / n + '0';
		num -= (num / n) * n;
		n /= 10;
	}
	return (rtn);
}
