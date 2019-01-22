/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:31:33 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/18 18:00:57 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_foreach(void *vector, void (c)(void *))
{
	void	*data;
	size_t	len;
	size_t	i;

	i = 0;
	len = ((size_t *)vector)[2];
	while (i < len)
	{
		data = vector_get_elem(vector, i);
		(c)(data);
		i++;
	}
}
