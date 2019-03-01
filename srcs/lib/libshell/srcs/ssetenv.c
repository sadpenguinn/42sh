/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssetenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:50:20 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/28 17:42:45 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libshell.h"

/*
** Sets new environment variable. Value may be NULL.
** If variable already exists, it will be overwritten
*/

int				ssetenv(const char *key, const char *value)
{
	if (!key)
		return (SHERR_ERR);
	if ((hash_insert(key, value, g_hash_env) == HSH_ERR))
		return (SHERR_ERR);
	free_str_arr(&g_env.env);
	g_env.size = 0;
	g_env.filled = 0;
	fill_genv();
	if (!ft_strcmp(key, "PATH"))
	{
		destroy_path();
		init_path();
	}
	return (SHERR_OK);
}
