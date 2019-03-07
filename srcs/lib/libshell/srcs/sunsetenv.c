/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunsetenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:04:15 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/28 16:33:28 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libshell.h"

/*
** Unset environment variable. If variable is found in hash table
** SHERR_OK will be returned, else - SHERR_ERR
*/

static void		sunsetenv_sample(t_env *env, t_hash *hash_env)
{
	free_str_arr(&env->env);
	env->size = 0;
	env->filled = 0;
	fill_genv(env, hash_env);
}

int				sunsetenv(const char *key, int local)
{
	if (local == ENV_EXP)
	{
		if (hash_delete(key, g_hash_env) == HSH_ERR)
			return (SHERR_ERR);
		sunsetenv_sample(&g_env, g_hash_env);
	}
	else if (local == ENV_RO)
	{
		if (hash_delete(key, g_hash_roenv) == HSH_ERR)
			return (SHERR_ERR);
		sunsetenv_sample(&g_roenv, g_hash_roenv);
	}
	else
	{
		if (hash_delete(key, g_hash_env) == HSH_ERR &&
			hash_delete(key, g_hash_roenv) == HSH_ERR)
			return (SHERR_ERR);
		sunsetenv_sample(&g_env, g_hash_env);
		sunsetenv_sample(&g_roenv, g_hash_roenv);
	}
	return (SHERR_OK);
}
