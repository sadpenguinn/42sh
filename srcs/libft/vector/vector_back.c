/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:23:04 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/04 12:23:07 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	*vector_back(void *vector)
{
	size_t	*arr;

	arr = (size_t *)vector;
	arr = (size_t *)((char *)(arr + 3) + arr[0] * (arr[2] - 1));
	return ((void *)arr);
}
