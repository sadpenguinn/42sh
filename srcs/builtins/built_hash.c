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

void			print_bin(char *key, char *value)
{
	ft_putstr(key);
	ft_putchar('=');
	ft_putendl(value);
}

static void		build_hash_parse(char **av)
{
	if (!ft_strcmp(av[1], "-p"))
		built_hash_parg(av);
	else if (!ft_strcmp(av[1], "-R"))
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
		return ;
}

int				built_hash(char **av, char **env)
{
	env = NULL;
	if (!av[1])
	{
		destroy_path();
		init_path();
		hash_foreach(g_path, print_bin);
	}
	else
		build_hash_parse(av);
	return (SHERR_OK);
}
