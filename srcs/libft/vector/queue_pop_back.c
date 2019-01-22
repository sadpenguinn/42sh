/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 13:37:03 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/04 16:02:41 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		queue_pop_back(void **queue)
{
	size_t	*arr;

	arr = (size_t *)(*queue);
	if (vector_is_empty((void *)arr[1]))
	{
		while (!(vector_is_empty((void *)arr[0])))
		{
			if (!(vector_push_back((void **)(arr + 1), vector_back((void *)arr[0]))))
			{
				queue_free((void **)queue);
				return (0);
			}
			if (!(vector_pop_back((void **)(arr))))
			{
				queue_free((void **)queue);
				return (0);
			}
		}
	}
	if (!(vector_pop_back((void **)(arr + 1))))
	{
		queue_free((void **)queue);
		return (0);
	}
	return (1);
}
