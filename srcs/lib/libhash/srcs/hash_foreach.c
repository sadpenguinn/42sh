/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_foreach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:10:58 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/14 17:11:12 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Iterates the table
*/

void	hash_foreach(t_hshtb **table, \
								void (c)(void *content, size_t content_size))
{
	t_hshtb		*tmp;
	size_t		len;
	size_t		i;

	if (!table)
		return ;
	i = 1;
	len = ((t_hshinfo *)table[0]->content)->size;
	while (i < len)
	{
		tmp = table[i];
		while (tmp)
		{
			(c)(tmp->content, tmp->content_size);
			tmp = tmp->next;
		}
		i++;
	}
}
