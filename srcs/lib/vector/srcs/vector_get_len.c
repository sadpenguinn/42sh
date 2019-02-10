/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:24:04 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/06 17:20:05 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include <unistd.h>

size_t	vector_get_len(void *vector)
{
	size_t	*arr;

	arr = (size_t *)vector;
	return (arr[2]);
}
