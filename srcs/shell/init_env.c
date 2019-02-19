/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hash_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:05:27 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/18 14:25:50 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_env(char **env)
{
	t_hshtb	*cell;
	int		i;

	i = 0;
	if (!(g_hash_env = hash_init(INITIAL_ENV_HASH_SIZE, HSH_EQ_DJB2)))
		die();
	if (!(g_env = (char **)malloc(sizeof(char *) * INITIAL_ENV_HASH_SIZE)));
	while (env[i])
	{
		if ((cell = hash_insert(env[i], &g_hash_env)) && cell->content)
			g_env[i] = cell->content;
		i++;
	}
	while (i < INITIAL_ENV_HASH_SIZE)
	{
		g_env[i] = NULL;
		i++;
	}
}
