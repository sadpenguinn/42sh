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
#include "../includes/libshell.h"

/*
** Sets new environment variable. Value may be NULL.
** If variable already exists, it will be overwritten
*/

static void		ssetenv_sample(t_env *env, t_hash *hash_env)
{
	free_str_arr(&env->env);
	env->size = 0;
	env->filled = 0;
	fill_genv(env, hash_env);
}

int				ssetenv(const char *key, const char *value, int local)
{
	if (!key)
		return (SHERR_ERR);
	if (local == ENV_EXP)
	{
		if ((hash_insert(key, value, g_hash_env) == HSH_ERR))
			return (SHERR_ERR);
		ssetenv_sample(&g_env, g_hash_env);
	}
	else if (local == ENV_RO)
	{
		if ((hash_insert(key, value, g_hash_roenv) == HSH_ERR))
			return (SHERR_ERR);
		ssetenv_sample(&g_roenv, g_hash_roenv);
	}
	else
		return (SHERR_ERR);
	if (!ft_strcmp(key, "PATH"))
	{
		destroy_path();
		init_path();
	}
	return (SHERR_OK);
}
