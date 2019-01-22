/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:24:43 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/04 12:24:45 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vector_pop_back(void **vector)
{
	size_t	*arr;
	size_t	*tmp;
	size_t	size;

	arr = (size_t *)(*vector);
	if (arr[2] - 1 < ft_ceill(arr[1] / A / A) && arr[1] != ARR_SIZE
		&& arr[1] != ft_floorl(ARR_SIZE * A))
	{
		size = ft_ceill(arr[1] / A);
		if (!(tmp = (size_t *)malloc(sizeof(size_t) * 3 + size * arr[0])))
			return (0);
		memcpy((void *)tmp, (void *)arr, arr[0] * arr[2] +
				sizeof(size_t) * 3);
		tmp[1] = size;
		vector_free(vector);
		arr = tmp;
		*vector = arr;
	}
	arr[2]--;
	return (1);
}
