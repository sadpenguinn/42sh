/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:43:32 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 21:43:37 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Returns a pointer if there is match or NULL
*/

static t_hshtb		*hash_find_iter(t_hash *hash, t_hshindex index,
										const char *key, t_hshtb *ptr)
{
	t_hshindex	i;

	i = 0;
	if (index == hash->size)
	{
		index = i;
		i = 0;
		ptr = hash->table + i;
		while (i < index && (!ptr->key || (ptr->key &&
				ft_strcmp(key, ptr->key))))
		{
			ptr++;
			i++;
		}
		if (i == index)
			return (NULL);
	}
	return (ptr);
}

t_hshtb				*hash_find(const char *key, t_hash *hash)
{
	t_hshindex	index;
	t_hshtb		*ptr;

	if (!hash || !hash->table || !key)
		return (NULL);
	index = hash_index(key, hash);
	ptr = hash->table + index;
	while (index < hash->size && (!ptr->key || (ptr->key &&
			ft_strcmp(key, ptr->key))))
	{
		ptr++;
		index++;
	}
	if (!(ptr = hash_find_iter(hash, index, key, ptr)))
		return (NULL);
	if (!ft_strcmp(key, ptr->key))
		return (ptr);
	return (NULL);
}
