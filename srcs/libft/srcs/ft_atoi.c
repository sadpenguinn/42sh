/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:57:13 by bwerewol          #+#    #+#             */
/*   Updated: 2018/12/04 20:33:45 by bwerewol         ###   ########.fr       */
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
	{
		if ((num *= 5) < 0)
			return (sig == 1 ? -1 : 0);
		if ((num = num * 2 + (*nptr++ - '0')) < 0)
			return (sig == 1 ? -1 : 0);
	}
	return (num * sig);
}
