/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:54:03 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/21 10:13:32 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <stdint.h>

int		test_bytes(const char *p)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (p[i] == '\0')
			return (i);
		i++;
	}
	return (8);
}

size_t	ft_strlen(const char *str)
{
	const char			*p;
	const unsigned long	*lp;
	int					ret;

	p = str;
	while ((uintptr_t)p & LONGPTR_MASK)
	{
		if (*p == '\0')
			return (p - str);
		p++;
	}
	lp = (const unsigned long *)p;
	while (1)
	{
		if ((*lp - MASK_01) & MASK_80)
		{
			p = (const char *)lp;
			ret = test_bytes(p);
			if (ret != 8)
				return (p - str + ret);
		}
		lp++;
	}
	return (0);
}
