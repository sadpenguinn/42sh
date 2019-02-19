/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:24:55 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 16:51:28 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

static int 		hash_realloc(t_hash *hash, size_t new_size)
{
	t_hash	*new_hash;
	t_hshtb	*current;
	size_t	i;

	i = 0;
	if (!(new_hash = hash_init(new_size)))
		return (0);
	current = hash->table;
	while (i < hash->size)
	{
		if (current->key)
		{
			if(!(hash_insert(current->key, current->value, new_hash, current->data)))
			{
				hash_clean(hash);
				return (0);
			}
		}
		current++;
		i++;
	}
	current = hash->table;
	hash->table = new_hash->table;
	hash->size = new_hash->size;
	hash->filled = new_hash->filled;
	free(new_hash);
	free(current);
	return (1);
}

static size_t		hash_check_avail(t_hash *hash)
{
	float		avail;
	float		filled;

	avail = (float)hash->size / (float)100 * (float)HSH_PERCENTS_FILLED_MAX;
	filled = (float)hash->filled;
	if (filled > avail)
		return ((size_t)((float)hash->size / (float)100 * (float)HSH_PERCENTS_SIZE_REALLOC) + hash->size);
	return (0);
}

t_hshtb			*hash_insert_cell(char *key, char *value, t_hash *hash, t_hshindex index, void *data)
{
	t_hshindex	i;
	t_hshtb		*ptr;
	t_hshtb		new;

	i = index;
	ptr = hash->table + index;
	while (index < hash->size - 1 && ptr->key)
	{
		ptr++;
		index++;
	}
	if (index == hash->size)
	{
		index = i;
		i = 0;
		while (i < index && ptr->key)
		{
			ptr++;
			i++;
		}
		if (i == index)
			return (NULL);
	}
	new.key = ft_strdup(key);
	new.value = ft_strdup(value);
	new.data = data;
	ft_memmove((void *)ptr, (void *)&new, sizeof(t_hshtb));
	hash->filled++;
	return (ptr);
}

/*
** Function insert cell into the table. If cells count is greater
** then HSH_PERCENTS_FILLED_MAX define, table size will be increased by
** HSH_PERCENTS_SIZE_REALLOC
*/

t_hshtb			*hash_insert(char *key, char *value, t_hash *hash, void *data)
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
