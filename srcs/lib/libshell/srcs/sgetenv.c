/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgetenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:28:45 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 15:42:57 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libshell.h"

char	*sgetenv(const char *key)
{
	t_hshtb	*cell;

	if (!(cell = hash_find(key, g_hash_env)))
		return (NULL);
	return (cell->value);
}
