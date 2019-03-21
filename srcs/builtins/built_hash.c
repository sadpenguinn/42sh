/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:31:55 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/08 13:31:56 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "builtins.h"

int				hash_print_error(char *arg)
{
	sputcmderr(sstrerr(SHERR_INVSNTX), "hash", arg);
	return (SHERR_ERR);
}

void			hash_print_bin(char *key, char *value)
{
	ft_putstr(key);
	ft_putchar('=');
	ft_putendl(value);
}

static int		build_hash_parse(char **av)
{
	if (!ft_strcmp(av[1], "-p"))
		built_hash_parg(av);
	else if (!ft_strcmp(av[1], "-r"))
	{
		destroy_path();
		init_path();
	}
	else if (!ft_strcmp(av[1], "-d"))
		built_hash_darg(av);
	else if (!ft_strcmp(av[1], "-t"))
		built_hash_targ(av);
	else if (!ft_strcmp(av[1], "-l"))
		built_hash_larg(av);
	else
		return (hash_print_error(av[1]));
	return (SHERR_OK);
}

/*
** hash [-r] [-p filename] [-dt]
*/

int				built_hash(char **av, char **env)
{
	env = NULL;
	if (!av[1])
		hash_foreach(g_path, hash_print_bin);
	return (build_hash_parse(av));
}
