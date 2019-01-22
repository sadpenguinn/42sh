/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:03:01 by bwerewol          #+#    #+#             */
/*   Updated: 2018/11/20 18:03:02 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	mem = malloc(size);
	if (!mem)
		return ((void *)0);
	i = 0;
	while (i < size)
		((char*)mem)[i++] = 0;
	return (mem);
}
