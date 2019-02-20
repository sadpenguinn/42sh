/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unsetenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:37:30 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/20 15:52:52 by nkertzma         ###   ########.fr       */
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
		else
		{
			ft_putendl_fd("unsetenv: Invalud syntax", 2);
			return (0);
		}
		i++;
	}
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
	char	*value;

	env = NULL;
	if (!parse_flags(av, &key, &value))
		return (SHERR_ERR);
	if ((sunsetenv(key) == SHERR_ERR))
		return (SHERR_ERR);
	return (SHERR_OK);
}
