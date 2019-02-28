/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:00:39 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 12:51:34 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#define WSIZE sizeof(unsigned long int)

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*res;
	void	*end;

	if (!n || src == dest)
		return (dest);
	res = dest;
	end = ((unsigned char *)dest) + n;
	if (n > 128)
	{
		while ((dest + WSIZE) < end)
		{
			*((unsigned long int *)dest) = *((unsigned long int *)src);
			dest += WSIZE;
			src += WSIZE;
		}
	}
	while (dest < end)
	{
		*((char *)dest) = *((char *)src);
		src++;
		dest++;
	}
	return (res);
}
