/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_genv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:43:43 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/01 17:16:39 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"
#include "shell.h"

static char		*build_env_str(t_hshtb *ptr)
{
	char *str;

	str = ft_strjoin(ptr->key, "=", 0);
	if (ptr->value)
		str = ft_strjoin(str, ptr->value, 1);
	return (str);
}

static void		init_arr_env(t_env *env, t_hash *hash_env, size_t size)
{
	t_hshtb	*ptr;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	ptr = hash_env->table;
	while (i < size)
	{
		if (ptr->key)
		{
			env->env[k] = build_env_str(ptr);
			env->filled++;
			k++;
		}
		ptr++;
		i++;
	}
	size++;
	while (k < size)
	{
		env->env[k] = NULL;
		k++;
	}
}

/*
** Fills two-dimensional array with string implements environment
*/

void			fill_genv(t_env *env, t_hash *hash_env)
{
	size_t	size;

	size = hash_get_size(hash_env);
	env->size = size;
	env->filled = 0;
	env->env = (char **)xmalloc(sizeof(char *) * (size + 1));
	init_arr_env(env, hash_env, size);
}
