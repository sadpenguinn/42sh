/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hash_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:05:27 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/28 15:45:13 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			init_env(char **env)
{
	char	**pair;
	int		i;

	i = 0;
	g_hash_env = hash_init(INITIAL_ENV_HASH_SIZE, HSH_OW);
	g_hash_roenv = hash_init(INITIAL_ENV_HASH_SIZE, HSH_OW);
	while (env[i])
	{
		pair = split_env(env[i]);
		hash_insert(pair[0], pair[1], g_hash_env);
		free_str_arr(&pair);
		i++;
	}
	fill_genv(&g_env, g_hash_env);
	fill_genv(&g_roenv, g_hash_roenv);
}
