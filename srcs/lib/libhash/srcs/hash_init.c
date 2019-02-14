/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:59:34 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/14 16:07:13 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

static int	fill_info(t_hshtb **table, size_t size, int hashing)
{
	t_hshinfo	*info;

	if (!(info = (t_hshinfo *)malloc(sizeof(t_hshinfo))))
	{
		free(table[0]);
		free(table);
		return (0);
	}
	info->size = size;
	info->filled = 0;
	info->hashing = hashing;
	table[0]->content = info;
	table[0]->content_size = sizeof(info);
	table[0]->next = NULL;
	return (1);
}

/*
** Allocate hash table with passed size and hash function.
** Hashing algorithm transmitted as define
*/

t_hshtb		**hash_init(size_t size, int hashing)
{
	t_hshtb		**table;
	t_hshindex	i;

	if (!size || !(table = (t_hshtb **)malloc(sizeof(t_hshtb *) * (size + 2))))
		return (NULL);
	if (!(table[0] = (t_hshtb *)malloc(sizeof(t_hshtb))))
	{
		free(table);
		return (NULL);
	}
	if (!fill_info(table, size, hashing))
		return (NULL);
	i = 1;
	while (i < size + 1)
	{
		table[i] = NULL;
		i++;
	}
	return (table);
}
