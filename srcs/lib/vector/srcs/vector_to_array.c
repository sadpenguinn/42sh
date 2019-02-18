/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:25:53 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/04 12:25:55 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

int		vector_to_array(void **vector)
{
	size_t	*arr;
	size_t	*tmp;
	size_t	n;

	arr = (size_t *)(*vector);
	n = arr[2] * arr[0];
	if (!(tmp = (size_t *)malloc(n)))
		return (0);
	ft_memcpy((void *)tmp, (void *)(arr + 3), n);
	vector_free(vector);
	*vector = tmp;
	return (1);
}
