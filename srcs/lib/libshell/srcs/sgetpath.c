/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgetpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 22:40:17 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 21:33:11 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libshell.h"

static char *get_path(char *key, char *value)
{
	size_t	klen;
	size_t	vlen;

	klen = ft_strlen(key);
	vlen = ft_strlen(value);
	while (vlen > 0 && klen > 0)
	{
		if (key[klen - 1] != value[vlen - 1])
			break ;
		klen--;
		vlen--;
	}
	return (ft_strsub(value, 0, vlen));
}

static int	validate_sum(char *key, char *value)
{
	struct stat	stats;
	t_hshtb		*cell;
	char 		*path;
	char 		*sum;

	path = get_path(key, value);
	if (!(cell = hash_find(path, g_path_sums)))
	{
		ft_strdel(&path);
		return (0);
	}
	if ((stat(key, &stats) == -1))
	{
		ft_strdel(&path);
		return (1);
	}
	sum = ft_itoa(stats.st_mtimespec.tv_sec);
	if (!ft_strcmp(sum, path))
	{
		ft_strdel(&sum);
		ft_strdel(&path);
		return (1);
	}
	ft_strdel(&sum);
	ft_strdel(&path);
	return (0);
}

char		*sgetpath(const char *bin)
{
	t_hshtb		*cell;

	if (!(cell = hash_find(bin, g_path)))
		return (NULL);
	if (!validate_sum(cell->key, cell->value))
	{
		destroy_path();
		init_path();
	}
	if (!(cell = hash_find(bin, g_path)))
		return (NULL);
	return (cell->value);
}
