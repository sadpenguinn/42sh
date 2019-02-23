/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:00:31 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#define WSIZE sizeof(unsigned long int)

void	*ft_memset(void *s, int c, size_t n)
{
	void				*res;
	void				*end;
	unsigned long int	set;

	res = s;
	end = (char *)s + n;
	if (n > 128)
	{
		set = (unsigned char)c;
		set = (set | set << 8);
		set = (set | set << 16);
		set = (set | set << 32);
		while ((s + WSIZE) < end)
		{
			*((unsigned long int *)s) = set;
			s += WSIZE;
		}
	}
	while (s < end)
	{
		*((unsigned char *)s) = (unsigned char)c;
		s++;
	}
	return (res);
}
