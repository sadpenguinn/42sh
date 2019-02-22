/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:22:20 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Dan Bernstein hashing algorithm for variable length strings
** http://www.cse.yorku.ca/~oz/hash.html
*/

static t_hshindex	djb2(const char *content)
{
	t_hshindex	index;
	size_t		i;
	int			c;

	i = 0;
	index = 5381;
	while (content[i])
	{
		c = content[i];
		index = ((index << 5) + index) + c;
		i++;
	}
	return (index);
}

/*
** Looks up the index of an item in a table.
** At hash or key == NULL, behavior is undefined
*/

t_hshindex			hash_index(const char *key, t_hash *hash)
{
	t_hshindex	index;

	index = djb2(key);
	index = index % hash->size;
	return (index);
}
