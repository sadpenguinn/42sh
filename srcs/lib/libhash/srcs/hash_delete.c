/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:38:30 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/14 17:07:56 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Remove one cell in the table
*/

void	hash_delete(void *content, size_t content_size, t_hshtb **table, \
				int (c)(void *el1, size_t cs1, void *el2, size_t cs2))
{
	t_hshtb		*tmp;
	t_hshtb		*stmp;
	t_hshindex	index;
	t_hshinfo	*info;

	stmp = NULL;
	info = (t_hshinfo *)(table[0]->content);
	index = hash_index(content, content_size, table, info->hashing);
	tmp = table[index];
	while (tmp && !(c)(tmp->content, tmp->content_size, content, content_size))
	{
		stmp = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return ;
	if (stmp)
		stmp->next = tmp->next;
	else
		table[index] = tmp->next;
	free(tmp);
}
