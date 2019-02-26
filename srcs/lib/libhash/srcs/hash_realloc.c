/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:57:01 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 21:43:37 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

static void		hash_realloc_fill(t_hash *hash, t_hash *new_hash)
{
	hash_foreach(hash, hash_free_fileds);
	free(hash->table);
	hash->table = new_hash->table;
	hash->size = new_hash->size;
	hash->filled = new_hash->filled;
	hash->overwrite = new_hash->overwrite;
	free(new_hash);
}

int				hash_realloc(t_hash *hash, size_t new_size)
{
	t_hash	*new_hash;
	t_hshtb	*current;
	size_t	i;

	i = 0;
	new_hash = hash_init(new_size, hash->overwrite);
	current = hash->table;
	while (i < hash->size)
	{
		if (current->key)
		{
			if (!(hash_insert(current->key, current->value, new_hash)))
			{
				hash_clean(&hash);
				return (0);
			}
		}
		current++;
		i++;
	}
	hash_realloc_fill(hash, new_hash);
	return (1);
}
