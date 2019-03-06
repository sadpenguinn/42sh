/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unsetenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:37:30 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 18:11:23 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int		parse_flags(char **av, char **key)
{
	if (!av[1])
	{
		sputcmderr(sstrerr(SHERR_INVSNTX), "unsetenv", "");
		return (0);
	}
	if (av[2])
	{
		sputcmderr(sstrerr(SHERR_INVSNTX), "unsetenv", av[2]);
		return (0);
	}
	*key = av[1];
	return (1);
}

/*
** Removes variable from the environment.
** Following syntax are supported:
** unsetenv USER
*/

int				built_unsetenv(char **av, char **env)
{
	char	*key;

	env = NULL;
	if (!parse_flags(av, &key))
		return (SHERR_ERR);
	if ((sunsetenv(key, ENV_EXP) == SHERR_ERR))
	{
		ft_putstr_fd("unsetenv: Variable '", STDERR_FILENO);
		ft_putstr_fd(av[1], STDERR_FILENO);
		ft_putendl_fd("' was not found", STDERR_FILENO);
		return (SHERR_ERR);
	}
	return (SHERR_OK);
}
