/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xglob.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:40:02 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/20 13:32:56 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libshell.h"

static size_t	get_files_count(char *path)
{
	DIR				*dirp;
	size_t			count;

	count = 0;
	if (!(dirp = opendir(path)))
		return (count);
	while (readdir(dirp))
		count++;
	closedir(dirp);
	return (count);
}

void			glob_free(char ***matches, size_t i)
{
	while (i != (size_t)-1)
	{
		free((*matches)[i]);
		i--;
	}
	free(*matches);
	*matches = NULL;
}

static int		read_dir(DIR *dirp, char *pattern, char ***matches, size_t *cnt)
{
	struct dirent	*cdir;
	size_t			i;

	i = 0;
	while ((cdir = readdir(dirp)))
	{
		if (xmatch(cdir->d_name, pattern))
		{
			if (!((*matches)[i] = ft_strdup(cdir->d_name)))
			{
				glob_free(matches, i);
				return (-1);
			}
			i++;
		}
	}
	*cnt = i;
	(*matches)[i] = NULL;
	return ((int)i);
}

/*
** Searches by file names in folder 'path' according to the 'pattern'.
** Matches stores in 'matches' array, size array stores in cnt
*/

int				xglob(char *pattern, char *path, char ***matches, size_t *cnt)
{
	DIR				*dirp;
	size_t			arr_len;

	if (!pattern && !path && !matches)
		return (1);
	if (!(dirp = opendir(path)))
		return (1);
	if (!(arr_len = get_files_count(path)))
		return (1);
	if (!(*matches = (char **)malloc(sizeof(char *) * (arr_len + 1))))
		return (1);
	if ((read_dir(dirp, pattern, matches, cnt) == -1))
		return (1);
	closedir(dirp);
	return (0);
}
