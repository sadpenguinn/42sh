/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:28:39 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 22:08:15 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_read_dir(char *dir, DIR *dirp)
{
	struct dirent   *cdir;
	char			*path;

	while ((cdir = readdir(dirp)))
	{
		path = ft_strjoin(dir, "/", 0);
		path = ft_strjoin(path, cdir->d_name, 1);
		hash_insert(cdir->d_name, path, g_path, dir);
		ft_strdel(&path);
	}
}

void	init_paths(char **paths)
{
	struct stat	stats;
	DIR			*dirp;
	t_hshtb		*cell;
	int 		i;

	i = 0;
	while (paths[i])
	{
		if (!(dirp = opendir(paths[i])))
		{
			sputerr(sstrerr(SHERR_ENOENT));
			continue ;
		}
		stat(paths[i], &stats);
		cell = hash_insert(paths[i], ft_itoa((int)stats.st_mtimespec.tv_sec), g_path_sums, NULL);
		init_read_dir(cell->key, dirp);
		closedir(dirp);
		i++;
	}
}

void 	init_path(void)
{
	char 	**paths;
	t_hshtb	*cell;

	if (!(g_path_sums = hash_init(INITIAL_PATH_SUMS_HASH_SIZE)))
		die();
	if (!(g_path = hash_init(INITIAL_PATH_HASH_SIZE)))
		die();
	if (!(cell = hash_find("PATH", g_hash_env)))
		return ;
	ft_putendl(cell->value);
	paths = ft_strsplit(cell->value, ':');
	init_paths(paths);
	free_str_arr(&paths);
}
