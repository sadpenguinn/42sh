/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_get_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:37:18 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 22:32:01 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Returns size of table
*/

size_t		hash_get_size(t_hash *hash)
{
	if (!hash || !hash->table)
		return ((size_t)HSH_ERR);
	return (hash->size);
}
