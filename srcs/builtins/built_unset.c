/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:15:42 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/25 14:15:45 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell.h"
#include "execute.h"

int			unset_executen(char **av)
{
	int		i;

	i = 0;
	av = unset_for(av);
	while (av[i])
	{
		if (sgetenv(av[i], ENV_ALL))
		{
			hash_delete(av[i], g_hash_env);
			hash_delete(av[i], g_hash_roenv);
			ssetenv(av[i], "", ENV_EXP);
		}
		i++;
	}
	return (SHERR_OK);
}

int			unset_executef(char **av)
{
	int		i;

	i = 0;
	av = unset_for(av);
	while (av[i])
	{
		unset_delete_function(av[i]);
		i++;
	}
	return (SHERR_OK);
}

int			unset_executev(char **av)
{
	int		i;

	i = 0;
	av = unset_for(av);
	while (av[i])
	{
		hash_delete(av[i], g_hash_env);
		hash_delete(av[i], g_hash_roenv);
		free_str_arr(&g_env.env);
		free_str_arr(&g_roenv.env);
		fill_genv(&g_env, g_hash_env);
		fill_genv(&g_roenv, g_hash_roenv);
		i++;
	}
	return (SHERR_OK);
}

int			unset_execute(char **av)
{
	int i;

	i = 0;
	av = unset_for(av);
	while (av[i])
	{
		unset_delete_function(av[i]);
		hash_delete(av[i], g_hash_env);
		hash_delete(av[i], g_hash_roenv);
		free_str_arr(&g_env.env);
		free_str_arr(&g_roenv.env);
		fill_genv(&g_env, g_hash_env);
		fill_genv(&g_roenv, g_hash_roenv);
		i++;
	}
	return (SHERR_OK);
}

/*
** Remove each variable or function name
** unset [-fnv] [name]
** If the -v option is given, each name refers to a shell variable
** and that variable is removed
** If the -f option is given, each name refers to a shell function
** and that function is removed
** If the -n option is given, each name refers to a shell variable
** and that variable value is removed
*/

int			built_unset(char **av, char **env)
{
	int		flags[3];

	env = NULL;
	ft_memset(flags, 0, sizeof(int) * 3);
	if (!av[1])
		return (unset_destroy_all());
	if (!unset_parse_flags(av, flags))
		return (SHERR_ERR);
	if (flags[1])
		return (unset_executen(av));
	else if (flags[0])
		return (unset_executef(av));
	else if (flags[2])
		return (unset_executev(av));
	return (unset_execute(av));
}
