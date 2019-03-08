/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:14:32 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/08 14:14:34 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	ind(char c, const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int			ft_atoi_base(const char *nptr, const char *base)
{
	int		result;
	int		neg;
	int		blen;

	result = 0;
	blen = (int)ft_strlen(base);
	if (blen < 2)
		return (0);
	while (ft_isblank(*nptr))
		nptr++;
	neg = *nptr == '-';
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (ind(*nptr, base) < blen)
		result = result * blen - ind(*nptr++, base);
	return (neg ? result : -result);
}
