/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:13:07 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/17 19:46:46 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

int		vector_push_back(void **vector, const void *data)
{
	size_t	*arr;
	size_t	*tmp;
	size_t	n;

	arr = (size_t *)(*vector);
	if (arr[1] == arr[2])
	{
		if (!(tmp = (size_t *)malloc(sizeof(size_t) * 3 +
						arr[0] * ft_floorl(arr[1] * A))))
			return (0);
		ft_memcpy((void *)tmp, (void *)arr, arr[0] * arr[2] +
				sizeof(size_t) * 3);
		tmp[1] = ft_floorl(tmp[1] * A);
		vector_free(vector);
		arr = tmp;
		*vector = arr;
	}
	arr[2]++;
	n = arr[0];
	arr = (size_t *)((char *)(arr + 3) + arr[0] * (arr[2] - 1));
	ft_memcpy((void *)arr, data, n);
	return (1);
}
