/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:38:30 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 14:14:47 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Remove one cell from the table
*/

int 	hash_delete(char *key, t_hash *hash)
{
	t_hshtb		*cell;

	if (!(cell = hash_find(key, hash)))
		return (HSH_ERR);
	free(cell->key);
	free(cell->value);
	ft_memset((void *)cell, '\0', sizeof(t_hshtb));
	return (HSH_OK);
}

