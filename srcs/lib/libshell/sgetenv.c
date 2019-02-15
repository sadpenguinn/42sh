/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:28:45 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/15 18:46:19 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libshell.h"

char 	*sgetenv(char *key)
{
	t_hshtb	*cell;
	size_t 	len;

	if (!key)
		return (NULL);
	len = ft_strlen(key);
	if (!(cell = hash_find(key, len, g_hash_env, keyvaluecmp)))
		return (NULL);
	if (!cell->content)
		return (NULL);
	return ((char *)(cell->content) + len + 1);
}
