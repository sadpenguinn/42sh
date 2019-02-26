/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:27:01 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 18:11:23 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int		parse_flags(char **av, char **key, char **value)
{
	if (!av[1] || !av[2])
	{
		sputcmderr(sstrerr(SHERR_INVSNTX), "setenv", "");
		return (0);
	}
	if (av[3])
	{
		sputcmderr(sstrerr(SHERR_INVSNTX), "setenv", av[3]);
		return (0);
	}
	*key = av[1];
	*value = av[2];
	return (1);
}

/*
** Adds variable to the environment.
** Following syntax are supported:
** setenv USER pahom
*/

int				built_setenv(char **av, char **env)
{
	char	*key;
	char	*value;

	env = NULL;
	if (!parse_flags(av, &key, &value))
		return (SHERR_ERR);
	ssetenv(key, value);
	return (SHERR_OK);
}
