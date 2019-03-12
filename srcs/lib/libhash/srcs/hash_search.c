/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_insert_overwrite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:31:46 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/26 18:49:29 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

static t_hshtb			*hash_bsearch(t_hash *hash, t_hshindex index,
												t_hshtb *ptr, const char *key)
{
	t_hshindex	i;

	i = 0;
	ptr = hash->table;
	while (i < index && (ptr->key && ft_strcmp(ptr->key, key)))
	{
		ptr++;
		i++;
	}
	if (i == index)
		return (NULL);
	return (ptr);
}

/*
** Internal function for search empty cell
*/

t_hshtb					*hash_search(const char *key, t_hash *hash,
														t_hshindex index)
{
	t_hshtb		*ptr;

	ptr = hash->table + index;
	while (index < hash->size && (ptr->key && ft_strcmp(ptr->key, key)))
	{
		ptr++;
		index++;
	}
	if (index == hash->size)
		if (!(ptr = hash_bsearch(hash, index, ptr, key)))
			return (NULL);
	return (ptr);
}
