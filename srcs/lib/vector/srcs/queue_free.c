/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:42:17 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/04 15:26:08 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	queue_free(void **queue)
{
	size_t	**arr;

	arr = (size_t **)queue;
	if (!arr)
		return ;
	vector_free((void **)(*arr + 0));
	vector_free((void **)(*arr + 1));
	free(*arr);
	*arr = 0;
}
