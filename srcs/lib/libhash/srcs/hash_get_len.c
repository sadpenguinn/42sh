/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_get_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:41:02 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** Returns length of table
*/

size_t		hash_get_len(t_hash *hash)
{
	if (!hash || !hash->table)
		return ((size_t)HSH_ERR);
	return (hash->filled);
}
