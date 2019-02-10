/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_front.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:16:32 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/04 14:24:18 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	*queue_front(void *queue)
{
	size_t	*arr;

	arr = (size_t *)queue;
	if (vector_is_empty((void *)(arr[1])))
		return (vector_front((void *)arr[0]));
	return (vector_back((void *)arr[1]));
}
