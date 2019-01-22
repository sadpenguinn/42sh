/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:00:18 by bwerewol          #+#    #+#             */
/*   Updated: 2018/11/27 16:59:56 by bwerewol         ###   ########.fr       */
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
