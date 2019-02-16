/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:08:10 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/16 15:37:45 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Function doest't work
*/

void	read_path_dir(char *dir, DIR *dirp)
{
	struct dirent   *cdir;
	char			*path;
	char 			*str;

	while ((cdir = readdir(dirp)))
	{
		path = ft_strjoin(dir, "/", 0);
		path = ft_strjoin(path, cdir->d_name, 1);
		if (!(hash_find(cdir->d_name, g_path, keyvaluecmp)))
		{
			str = ft_strjoin(cdir->d_name, "=", 0);
			str = ft_strjoin(str, path, 0);
			hash_insert(str, &g_path);
		}
		ft_strdel(&path);
	}
}

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
		read_path_dir(paths[i], dirp);
		closedir(dirp);
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
	if (!(cell = hash_find("PATH", g_hash_env, keyvaluecmp)))
		return ;
	path = (cell->content) + 5;
	if (!(paths = ft_strsplit(path, ':')))
		die();
	fill_path(paths);
	free_str_arr(paths);
}
