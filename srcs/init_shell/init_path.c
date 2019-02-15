/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:08:10 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/15 18:26:05 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Function doest't work
*/

void	fill_path(char **paths)
{
	DIR		*dirp;
	int 	i;

	i = 0;
	while (paths[i])
	{
		if (!(dirp = opendir(paths[i])))
		{
			serror(sstrerr(SHERR_ENOENT));
			continue ;
		}
		i++;
	}
}

void	init_path(void)
{
	t_hshtb	*cell;
	char 	*path;
	char 	**paths;

	if (!(g_path = hash_init(INITIAL_PATH_HASH_SIZE, HSH_EQ_DJB2)))
		die();
	if (!(cell = hash_find("PATH", 4, g_hash_env, keyvaluecmp)))
		return ;
	path = (char *)(cell->content) + 5;
	if (!(paths = ft_strsplit(path, ':')))
		die();
	fill_path(paths);
}
