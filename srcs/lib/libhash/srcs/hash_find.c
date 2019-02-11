/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:43:32 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/11 19:10:21 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_hshtb		*hash_find(void *content, size_t content_size, \
	t_hshtb **table, int (c)(void *el1, size_t cs1, void *el2, size_t cs2))
{
	t_hshtb		*tmp;
	t_hshinfo	*info;

	info = (t_hshinfo *)(table[0]->content);
	tmp = table[hash_index(content, content_size, table, info->hashing)];
	while (tmp && !(c)(tmp->content, tmp->content_size, content, content_size))
		tmp = tmp->next;
	return (tmp);
}
