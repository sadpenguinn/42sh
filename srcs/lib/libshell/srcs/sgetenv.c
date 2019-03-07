/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgetenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:28:45 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/28 14:22:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libshell.h"

/*
** Returns pointer to string in hash table represents environment variable.
** If there is no variable, NULL will be returned
*/

char	*sgetenv(const char *key, int local)
{
	t_hshtb	*cell;

	if (local == ENV_EXP)
	{
		if (!(cell = hash_find(key, g_hash_env)))
			return (NULL);
	}
	else if (local == ENV_RO)
	{
		if (!(cell = hash_find(key, g_hash_roenv)))
			return (NULL);
	}
	else
	{
		if (!(cell = hash_find(key, g_hash_env)) &&
			!(cell = hash_find(key, g_hash_roenv)))
			return (NULL);
	}
	return (cell->value);
}
