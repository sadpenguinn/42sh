/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_hash_reqmts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:02:26 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/08 14:02:28 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "builtins.h"

void			built_hash_parg(char **av)
{
	char	*path;

	if (av[2] && av[3])
	{
		path = ft_strjoin(av[2], "/", 0);
		path = ft_strjoin(path, av[3], 1);
		if (access(path, X_OK) == -1)
		{
			ft_strdel(&path);
			return ;
		}
		hash_delete(av[3], g_path);
		hash_insert(av[3], av[2], g_path);
		ft_strdel(&path);
	}
	else
		return ;
}

void			built_hash_darg(char **av)
{
	int		i;

	if (!av[2])
		return ;
	i = 2;
	while (av[i])
	{
		hash_delete(av[i], g_path);
		i++;
	}
}

void			built_hash_targ(char **av)
{
	t_hshtb	*cell;
	int		i;

	if (!av[2])
		return ;
	i = 2;
	while (av[i])
	{
		if ((cell = hash_find(av[i], g_path)))
			hash_print_bin(cell->key, cell->value);
		i++;
	}
}

void			built_hash_larg(char **av)
{
	t_hshtb	*cell;
	int		i;

	if (!av[2])
		hash_foreach(g_path, hash_print_bin);
	else
	{
		i = 2;
		while (av[i])
		{
			if ((cell = hash_find(av[i], g_path)))
				hash_print_bin(cell->key, cell->value);
			i++;
		}
	}
}
