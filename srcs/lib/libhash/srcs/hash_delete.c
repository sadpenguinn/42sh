/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:38:30 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/16 15:07:21 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Remove one cell in the table
*/

int 	hash_delete(void *content, t_hshtb **table, \
				int (c)(char *el1, char *el2))
{
	t_hshtb		*tmp;
	t_hshtb		*stmp;
	t_hshindex	index;
	t_hshinfo	*info;

	stmp = NULL;
	info = (t_hshinfo *)(table[0]->content);
	index = hash_index(content, table, info->hashing);
	tmp = table[index];
	while (tmp && !(c)(tmp->content, content))
	{
		stmp = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return(0);
	if (stmp)
		stmp->next = tmp->next;
	else
		table[index] = tmp->next;
	free(tmp);
	info->filled--;
	return (1);
}
