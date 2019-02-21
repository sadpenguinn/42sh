/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hash_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:05:27 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		init_arr_env(size_t size)
{
	t_hshtb	*ptr;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	ptr = g_hash_env->table;
	while (i < size)
	{
		if (ptr->key)
		{
			g_env[k] = (char *)ptr->data;
			k++;
		}
		ptr++;
		i++;
	}
	size++;
	while (k < size)
	{
		g_env[k] = NULL;
		k++;
	}
}

void			init_env(char **env)
{
	char	**pair;
	size_t	size;
	int		i;

	i = 0;
	g_hash_env = hash_init(INITIAL_ENV_HASH_SIZE);
	while (env[i])
	{
		pair = split_env(env[i]);
		hash_insert(pair[0], pair[1], g_hash_env, ft_strdup(env[i]));
		free_str_arr(&pair);
		i++;
	}
	size = hash_get_size(g_hash_env);
	g_env = (char **)xmalloc(sizeof(char *) * (size + 1));
	init_arr_env(size);
}
