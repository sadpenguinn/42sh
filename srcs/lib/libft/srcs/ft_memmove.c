/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:00:18 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 10:41:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	long int sz;

	if (src == dest)
		return (dest);
	if (src < dest)
	{
		sz = n - 1;
		while (sz != -1)
		{
			((char *)dest)[sz] = ((const char *)src)[sz];
			sz--;
		}
	}
	else
	{
		sz = 0;
		while ((size_t)sz < n)
		{
			((char *)dest)[sz] = ((const char *)src)[sz];
			sz++;
		}
	}
	return (dest);
}
