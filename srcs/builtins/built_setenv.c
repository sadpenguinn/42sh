/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:27:01 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/20 15:51:27 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int		parse_flags(char **av, char **key, char **value)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (i == 1)
			*key = av[i];
		else if (i == 2)
			*value = av[i];
		else
		{
			ft_putendl_fd("setenv: Invalud syntax", 2);
			return (0);
		}
		i++;
	}
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
