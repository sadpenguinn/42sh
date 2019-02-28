/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:54:39 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 12:51:35 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char		*ft_itoa_base(long int num, int base)
{
	long long	ln;
	int			len;
	char		sign;
	char		*barr;
	char		*str;

	if (base < 2 || base > 16)
		return ((char *)0);
	barr = "0123456789ABCDEF";
	sign = (num < 0) ? 1 : 0;
	ln = sign ? -num : num;
	len = (sign && base == 10) ? 1 : 0;
	while (num /= base)
		len++;
	if (!(str = ft_strnew(len + 1)))
		return ((char *)0);
	while (len >= 0)
	{
		str[len--] = barr[ln % base];
		ln /= base;
	}
	if (sign && base == 10)
		*str = '-';
	return (str);
}
