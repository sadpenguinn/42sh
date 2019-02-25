/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:28:39 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 21:15:57 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		init_read_dir(char *dir, DIR *dirp)
{
	struct dirent	*cdir;
	char			*path;

	while ((cdir = readdir(dirp)))
	{
		if (!ft_strcmp(cdir->d_name, ".") || !ft_strcmp(cdir->d_name, ".."))
			continue ;
		path = ft_strjoin(dir, "/", 0);
		path = ft_strjoin(path, cdir->d_name, 1);
		if (access(path, X_OK) == -1)
		{
			ft_strdel(&path);
			continue;
		}
		hash_insert(cdir->d_name, path, g_path);
		ft_strdel(&path);
	}
}

static void		init_paths(char **paths)
{
	struct stat	stats;
	DIR			*dirp;
	t_hshtb		*cell;
	char		*sum;
	int			i;

	i = 0;
	while (paths[i])
	{
		if (!(dirp = opendir(paths[i])) || (stat(paths[i], &stats) == -1))
		{
			i++;
			continue ;
		}
		sum = ft_itoa(stats.st_mtimespec.tv_sec);
		if (!(cell = hash_insert(paths[i], sum, g_path_sums)))
		{
			ft_strdel(&sum);
			i++;
			continue ;
		}
		ft_strdel(&sum);
		init_read_dir(cell->key, dirp);
		closedir(dirp);
		i++;
	}
}

void			init_path(void)
{
	char	**paths;
	t_hshtb	*cell;

	g_path_sums = hash_init(INITIAL_PATH_SUMS_HASH_SIZE, HSH_NOW);
	g_path = hash_init(INITIAL_PATH_HASH_SIZE, HSH_NOW);
	if (!(cell = hash_find("PATH", g_hash_env)))
		return ;
	paths = ft_strsplit(cell->value, ':');
	init_paths(paths);
	free_str_arr(&paths);
}
