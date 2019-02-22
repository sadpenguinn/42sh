/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnum_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 20:14:37 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnum_base(char *str, long int num, int base)
{
	long long	ln;
	int			len;
	int			ret;
	int			sign;
	char		*barr;

	if (base < 2 || base > 16)
		return (0);
	barr = "0123456789ABCDEF";
	sign = (num < 0) ? 1 : 0;
	ln = sign ? -num : num;
	len = (sign && base == 10) ? 1 : 0;
	while (num /= base)
		len++;
	ret = len;
	while (len >= 0)
	{
		str[len--] = barr[ln % base];
		ln /= base;
	}
	if (sign && base == 10)
		*str = '-';
	return (++ret);
}
