/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:23:35 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/04 12:23:36 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_free(void **vector)
{
	size_t	**arr;

	arr = (size_t **)(vector);
	if (!(arr))
		return ;
	free(*arr);
	*arr = NULL;
}
