/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:19:29 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 15:02:16 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"

/*
** The function just cleans the table
*/

void		hash_free_fileds(char *key, char *value)
{
	free(key);
	free(value);
}

int 		hash_clean(t_hash *hash)
{
	if (!hash)
		return (HSH_ERR);
	if (!hash->table)
	{
		free(hash);
		return (HSH_ERR);
	}
	hash_foreach(hash, hash_free_fileds);
	free(hash->table);
	free(hash);
	return (HSH_OK);
}
