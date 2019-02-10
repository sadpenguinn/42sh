/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:21:08 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/04 13:16:19 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	*queue_create(size_t elem_byte_size)
{
	size_t	*arr;

	if (!(arr = (size_t *)malloc(sizeof(size_t) * 2)))
		return (0);
	arr[0] = 0;
	arr[1] = 0;
	if (!(arr[0] = (size_t)vector_create(elem_byte_size)))
	{
		queue_free((void **)&arr);
		return (0);
	}
	if (!(arr[1] = (size_t)vector_create(elem_byte_size)))
	{
		queue_free((void **)&arr);
		return (0);
	}
	return ((void *)arr);
}
