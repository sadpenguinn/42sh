/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:22:20 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/16 14:36:44 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Looks up the index of an item in a table. 'c' argument
** is hashing algorithm define. If c does't correspond
** to more than one define djb2 will be selected
*/

t_hshindex			hash_index(void *content, t_hshtb **table, int c)
{
	t_hshindex	index;

	if (c == HSH_DJB2)
		index = djb2(content);
	else if (c == HSH_EQ_DJB2)
		index = eq_djb2(content);
	else
		index = djb2(content);
	index = index % ((t_hshinfo *)table[0]->content)->size;
	if (!index)
		return (index + 1);
	return (index);
}
