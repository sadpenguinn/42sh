/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hash_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:05:27 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/15 18:06:21 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_hash_env(char **env)
{
	int		i;

	if (!(g_hash_env = hash_init(INITIAL_ENV_HASH_SIZE, HSH_EQ_DJB2)))
		die();
	i = 0;
	while (env[i])
	{
		hash_insert((void *)(env[i]), &g_hash_env);
		i++;
	}
}
