/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:19:29 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/11 20:44:03 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

static void	clean_elem(t_hshtb *elem)
{
	t_hshtb		*tmp;
	t_hshtb		*stmp;

	tmp = elem;
	while (tmp)
	{
		stmp = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = stmp;
	}
}

void		hash_clean(t_hshtb ***tables)
{
	t_hshtb		**table;
	size_t		size;
	size_t		i;

	i = 0;
	table = *tables;
	size = ((t_hshinfo *)table[0]->content)->size;
	while (i < size + 1)
	{
		if (table[i])
			clean_elem(table[i]);
		table[i] = NULL;
		i++;
	}
	free(*tables);
	*tables = NULL;
}
