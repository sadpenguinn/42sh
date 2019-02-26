/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_foreach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:10:58 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 21:43:37 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Iterates the table
*/

int		hash_foreach(t_hash *hash, void (f)(char *key, char *value))
{
	t_hshtb	*ptr;
	size_t	size;
	size_t	i;

	if (!hash || !hash->table || !f)
		return (HSH_ERR);
	i = 0;
	size = hash->size;
	ptr = hash->table;
	while (i < size)
	{
		if (ptr->key)
			(f)(ptr->key, ptr->value);
		ptr++;
		i++;
	}
	return (HSH_OK);
}
