/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:24:55 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/24 14:23:40 by nkertzma         ###   ########.fr       */
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

static t_hshtb			*hash_insert_iter(t_hash *hash, t_hshindex index,
											t_hshtb *ptr, const char *key)
{
	t_hshindex	i;

	i = 0;
	if (index == hash->size)
	{
		index = i;
		i = 0;
		ptr = hash->table + i;
		while (i < index && (ptr->key && ft_strcmp(ptr->key, key)))
		{
			ptr++;
			i++;
		}
		if (i == index)
			return (NULL);
	}
	return (ptr);
}

static t_hshtb			*hash_insert_cell(const char *key, const char *value,
								t_hash *hash, t_hshindex index, const void *data)
{
	t_hshindex	i;
	t_hshtb		*ptr;
	t_hshtb		new;

	i = index;
	ptr = hash->table + index;
	while (index < hash->size && (ptr->key && ft_strcmp(ptr->key, key)))
	{
		ptr++;
		index++;
	}
	if (!(ptr = hash_insert_iter(hash, index, ptr, key)))
		return (NULL);
	ft_strdel(&ptr->key);
	ft_strdel(&ptr->value);
	new.key = ft_strdup(key);
	new.value = ft_strdup(value);
	new.data = (void *)data;
	ft_memmove((void *)ptr, (void *)&new, sizeof(t_hshtb));
	hash->filled++;
	return (ptr);
}

/*
** Function insert cell into the table. If cells count is greater
** then HSH_PERCENTS_FILLED_MAX define, table size will be increased by
** HSH_PERCENTS_SIZE_REALLOC
*/

t_hshtb					*hash_insert(const char *key, const char *value,
										t_hash *hash, const void *data)
{
	t_hshindex	index;
	size_t		new_size;

	if (!hash || !hash->table || !key)
		return (NULL);
	if ((new_size = hash_check_avail(hash)))
		if (!(hash_realloc(hash, new_size)))
			return (NULL);
	index = hash_index(key, hash);
	return (hash_insert_cell(key, value, hash, index, data));
}
