/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:24:55 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 21:56:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

static size_t			hash_check_avail(t_hash *hash)
{
	float		avail;
	float		filled;

	avail = (float)hash->size / (float)100 * (float)HSH_PERCENTS_FILLED_MAX;
	filled = (float)hash->filled;
	if (filled > avail)
	{
		return ((size_t)((float)hash->size / (float)100 *
							(float)HSH_PERCENTS_SIZE_REALLOC) + hash->size);
	}
	return (0);
}

static t_hshtb			*hash_insert_cell(const char *key, const char *value,
											t_hash *hash, t_hshindex index)
{
	t_hshtb		*ptr;
	t_hshtb		new;

	if (!(ptr = hash_search(key, hash, index)))
		return (NULL);
	if (ptr->key && hash->overwrite != HSH_OW)
		;
	else
	{
		ft_strdel(&ptr->key);
		ft_strdel(&ptr->value);
		new.key = ft_strdup(key);
		new.value = ft_strdup(value);
		ft_memmove((void *)ptr, (void *)&new, sizeof(t_hshtb));
		hash->filled++;
	}
	return (ptr);
}

/*
** Function insert cell into the table. If cells count is greater
** then HSH_PERCENTS_FILLED_MAX define, table size will be increased by
** HSH_PERCENTS_SIZE_REALLOC
*/

t_hshtb					*hash_insert(const char *key, const char *value,
															t_hash *hash)
{
	t_hshindex	index;
	size_t		new_size;

	if (!hash || !hash->table || !key)
		return (NULL);
	if ((new_size = hash_check_avail(hash)))
		if (!(hash_realloc(hash, new_size)))
			return (NULL);
	index = hash_index(key, hash);
	return (hash_insert_cell(key, value, hash, index));
}
