/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:43:32 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/16 14:40:25 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Returns a pointer if there is match, else NULL will be returned
*/

t_hshtb		*hash_find(void *content, t_hshtb **table, \
											int (c)(char *el1, char *el2))
{
	t_hshtb		*tmp;
	t_hshinfo	*info;

	if (!table)
		return (NULL);
	info = (t_hshinfo *)(table[0]->content);
	tmp = table[hash_index(content, table, info->hashing)];
	while (tmp && !(c)(tmp->content, content))
		tmp = tmp->next;
	return (tmp);
}
