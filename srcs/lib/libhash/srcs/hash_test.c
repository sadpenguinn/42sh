/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:18:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 14:14:47 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"
#include "libft.h"

static size_t		g_collisions = 0;
static t_hash		*g_hash = NULL;

void				hash_collisions(char *key, char *value)
{
	t_hshindex	index;
	t_hshtb		*ptr;

	index = hash_index(key, g_hash);
	ptr = g_hash->table + (sizeof(t_hshtb) * index);
	if (ft_strcmp(key, ptr->key))
		g_collisions++;
}

/*
** Counts the number of collision
*/

int 				hash_test(t_hash *hash)
{
	g_hash = hash;
	if (!(hash_foreach(hash, hash_collisions)))
		return (HSH_ERR);
	ft_putstr("Collision test: ");
	ft_putnbrendl((int)g_collisions);
	return (HSH_OK);
}