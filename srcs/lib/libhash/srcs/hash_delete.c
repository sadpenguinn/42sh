/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:38:30 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/22 21:11:08 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Remove one cell from the table
*/

int		hash_delete(const char *key, t_hash *hash)
{
	t_hshtb		*cell;

	if ((cell = hash_find(key, hash)) == HSH_ERR)
		return (HSH_ERR);
	ft_strdel(&cell->key);
	ft_strdel(&cell->value);
	ft_memset(cell, '\0', sizeof(t_hshtb));
	hash->filled--;
	return (HSH_OK);
}
