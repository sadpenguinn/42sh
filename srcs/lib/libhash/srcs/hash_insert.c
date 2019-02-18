/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:24:55 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/11 19:23:22 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"
#include "libft.h"

t_hshtb			*insert(void *content, size_t content_size, \
											t_hshtb **table, t_hshindex index)
{
	t_hshtb		*tmp;
	t_hshtb		*stmp;

	if (!(tmp = (t_hshtb *)malloc(sizeof(t_hshtb))))
		return (NULL);
	stmp = table[index];
	table[index] = tmp;
	tmp->next = stmp;
	if (!(tmp->content = malloc(content_size)))
	{
		free(tmp);
		return (NULL);
	}
	ft_memcpy(tmp->content, content, content_size);
	tmp->content_size = content_size;
	(((t_hshinfo *)table[0]->content)->filled)++;
	return (tmp);
}

static int		hash_check_avail(t_hshtb ***table)
{
	t_hshtb		**tmp_table;
	size_t		avail;
	size_t		filled;
	size_t		new_size;

	tmp_table = *table;
	avail = (float)((t_hshinfo *)tmp_table[0]->content)->size / (float)100 \
											* (float)HSH_PERCENTS_FILLED_MAX;
	filled = ((t_hshinfo *)tmp_table[0]->content)->filled;
	if (filled > avail)
	{
		new_size = (float)((t_hshinfo *)tmp_table[0]->content)->size / \
								(float)100 * (float)HSH_PERCENTS_SIZE_REALLOC;
		return (new_size);
	}
	return (0);
}

static void		hash_realloc(t_hshtb ***table, size_t new_size)
{
	t_hshtb		**tmp_table;
	t_hshtb		**new_table;
	t_hshtb		*tmp;
	size_t		i;

	i = 1;
	tmp_table = *table;
	if (!(new_table = hash_init(new_size, \
							((t_hshinfo *)((*table)[0]->content))->hashing)))
		return ;
	while (i < ((t_hshinfo *)tmp_table[0]->content)->size)
	{
		tmp = tmp_table[i++];
		while (tmp)
		{
			if (!(hash_insert(tmp->content, tmp->content_size, &new_table)))
			{
				hash_clean(&new_table);
				return ;
			}
			tmp = tmp->next;
		}
	}
	hash_clean(table);
	*table = new_table;
}

t_hshtb			*hash_insert(void *content, size_t content_size, \
															t_hshtb ***table)
{
	t_hshinfo	*info;
	t_hshindex	index;
	size_t		new_size;

	if ((new_size = hash_check_avail(table)))
		hash_realloc(table, new_size);
	info = (t_hshinfo *)((*table)[0]->content);
	index = hash_index(content, content_size, *table, info->hashing);
	return (insert(content, content_size, *table, index));
}
