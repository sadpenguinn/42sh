/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:57:13 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int			sig;
	long long	num;

	num = 0;
	sig = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\v' || *nptr == '\f' ||
			*nptr == '\r' || *nptr == '\t')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		sig = (*nptr++ == '-') ? -1 : 1;
	while (*nptr >= '0' && *nptr <= '9')
		num = num * 10 + (*nptr++ - '0');
	return (num * sig);
}
