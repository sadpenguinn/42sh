/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:54:03 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 12:51:34 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include "libft.h"

int		test_bytes(const char *p)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (p[i] == '\0')
			return (i);
		i++;
	}
	if (LONG_BIT == 64)
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
