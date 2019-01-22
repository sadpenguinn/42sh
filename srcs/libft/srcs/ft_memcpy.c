/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:00:39 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 16:35:14 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#define WSIZE sizeof(unsigned long int)

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*end;

	if (src == dest)
		return (dest);
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
		dest++;
	}
	return (dest);
}
