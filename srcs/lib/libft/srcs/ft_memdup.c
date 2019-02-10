/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:50:30 by bwerewol          #+#    #+#             */
/*   Updated: 2018/12/12 19:09:13 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *data, size_t size)
{
	void *new;

	if (!(new = malloc(size)))
		return ((void *)0);
	ft_memcpy(new, data, size);
	return (new);
}
