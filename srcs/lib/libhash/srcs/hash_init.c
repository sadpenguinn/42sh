/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:59:34 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:32 by nkertzma         ###   ########.fr       */
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
	hash = (t_hash *)xmalloc(sizeof(t_hash));
	table = (t_hshtb *)xmalloc(sizeof(t_hshtb) * size);
	ft_memset(hash, '\0', sizeof(t_hash));
	ft_memset(table, '\0', sizeof(t_hshtb) * size);
	hash->table = table;
	hash->size = size;
	hash->filled = 0;
	return (hash);
}
