/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssetenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:50:20 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/16 15:00:30 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libshell.h"

int 	ssetenv(char *key, char *value, int overwrite)
{
	char 	*str;

	if (!key)
		return (SHERR_ERR);
	str = ft_strjoin(key, "=", 0);
	if (value)
		str = ft_strjoin(str, value, 1);
	if (overwrite && hash_find(str, g_hash_env, keyvaluecmp))
		hash_delete(str, g_hash_env, keyvaluecmp);
	if (!(hash_insert(str, &g_hash_env)))
		return (SHERR_ERR);
	return (SHERR_OK);
}
