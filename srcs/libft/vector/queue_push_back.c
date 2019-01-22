/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:36:42 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/04 16:04:24 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		queue_push_back(void **queue, const void *data)
{
	size_t	*arr;

	arr = (size_t *)(*queue);
	if (!(vector_push_back((void **)(arr + 0), data)))
	{
		queue_free((void **)queue);
		return (0);
	}
	return (1);
}
