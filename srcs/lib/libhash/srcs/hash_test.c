/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:18:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 21:43:37 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

static size_t		g_collisions = 0;
static t_hash		*g_hash = NULL;

static void			hash_collisions(char *key, char *value)
{
	t_hshindex	index;
	t_hshtb		*ptr;

	value = NULL;
	index = hash_index(key, g_hash);
	ptr = g_hash->table + index;
	if (ft_strcmp(key, ptr->key))
		g_collisions++;
}

/*
** Counts the number of collision
*/

int					hash_test(t_hash *hash)
{
	g_hash = hash;
	if ((hash_foreach(hash, hash_collisions)) == HSH_ERR)
		return (HSH_ERR);
	ft_putstr(C_GREEN"Collision test: "C_DEFAULT);
	ft_putnbrendl((int)g_collisions);
	ft_putstr(C_GREEN"Size: "C_DEFAULT);
	ft_putnbrendl((int)hash->size);
	ft_putstr(C_GREEN"Filled: "C_DEFAULT);
	ft_putnbrendl((int)hash->filled);
	return (HSH_OK);
}
