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

char	*sgetenv(const char *key)
{
	t_hshtb	*cell;

	if (!(cell = hash_find(key, g_hash_env)))
		return (NULL);
	return (cell->value);
}
