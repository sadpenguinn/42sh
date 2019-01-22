/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:52:42 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/18 11:39:57 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	*vector_get_elem(void *vector, size_t i)
{
	size_t	*arr;

	arr = (size_t *)vector;
	if (i == 0)
		return ((void *)((char *)(arr + 3)));
	arr = (size_t *)((char *)(arr + 3) + arr[0] * i);
	return ((void *)arr);
}
