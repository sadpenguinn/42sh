/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:59:34 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 15:25:13 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Allocate hash table with passed size
*/

t_hash		*hash_init(size_t size)
{
	t_hash		*hash;
	t_hshtb		*table;

	if (HSH_PERCENTS_SIZE_REALLOC <= 0 || HSH_PERCENTS_FILLED_MAX <= 0 || !size)
		return (NULL);
	if (!(hash = (t_hash *)malloc(sizeof(t_hash))))
		return (NULL);
	if (!(table = (t_hshtb *)malloc(sizeof(t_hshtb) * size)))
	{
		free(hash);
		return (NULL);
	}
	ft_memset((void *)hash, '\0', sizeof(t_hash));
	ft_memset((void *)table, '\0', sizeof(t_hshtb) * size);
	hash->table = table;
	hash->size = size;
	hash->filled = 0;
	return (hash);
}
