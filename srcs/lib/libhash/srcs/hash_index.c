/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:22:20 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/14 16:55:52 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Looks up the index of an item in a table. 'c' argument
** is hashing algorithm define. If c does't correspond
** to more than one define djb2 will be selected
*/

t_hshindex			hash_index(void *content, size_t content_size, \
														t_hshtb **table, int c)
{
	t_hshindex	index;

	if (c == HSH_DJB2)
		index = djb2(content, content_size);
	else if (c == HSH_EQ_DJB2)
		index = eq_djb2(content);
	else
		index = djb2(content, content_size);
	index = index % ((t_hshinfo *)table[0]->content)->size;
	if (!index)
		return (index + 1);
	return (index);
}
