/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgetpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 22:40:17 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/02 19:09:42 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "shell.h"
#include "libshell.h"
#include "builtins.h"

static char	*get_path(char *key, char *value)
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

static int	free_sum(void *farg, void *sarg, int ret)
{
	if (farg)
		free(farg);
	if (sarg)
		free(sarg);
	return (ret);
}

static int	validate_sum(char *key, char *value)
{
	struct stat	stats;
	char		*path;
	char		*sum;

	path = get_path(key, value);
	if (!hash_find(path, g_path_sums))
		return (free_sum(path, NULL, 0));
	if ((stat(key, &stats) == -1))
		return (free_sum(path, NULL, 1));
	sum = ft_ltoa(STATS_TIME_SEC);
	if (!ft_strcmp(sum, path))
		return (free_sum(sum, path, 1));
	return (free_sum(sum, path, 0));
}

static int	find_builtin(const char *bin, void **ret)
{
	if (!ft_strcmp(bin, "cd"))
	{
		*ret = built_cd;
		return (PATH_NOFORK);
	}
	else if (!ft_strcmp(bin, "echo"))
		*ret = built_echo;
	else if (!ft_strcmp(bin, "env"))
		*ret = built_env;
	else if (!ft_strcmp(bin, "hash"))
	{
		*ret = built_hash;
		return (PATH_NOFORK);
	}
	else if (!ft_strcmp(bin, "setenv"))
	{
		*ret = built_setenv;
		return (PATH_NOFORK);
	}
	else if (!ft_strcmp(bin, "unsetenv"))
	{
		*ret = built_unsetenv;
		return (PATH_NOFORK);
	}
	else if (!ft_strcmp(bin, "exit"))
	{
		*ret = built_exit;
		return (PATH_NOFORK);
	}
	else if (!ft_strcmp(bin, "export"))
	{
		*ret = built_export;
		return (PATH_NOFORK);
	}
	else if (!ft_strcmp(bin, "set"))
	{
		*ret = built_set;
		return (PATH_NOFORK);
	}
	else
		return (PATH_NULL);
	return (PATH_BUILT);
}

/*
** Returns define declared in libshell.h.
** In 'ret' recorded pointer to functions (builtin) or
** path in hash table (binary)
*/

int			sgetpath(const char *bin, void **ret)
{
	t_hshtb		*cell;
	int			ret_built;

	if ((ret_built = find_builtin(bin, ret)) != PATH_NULL)
		return (ret_built);
	if (!(cell = hash_find(bin, g_path)))
		return (PATH_NULL);
	if (!validate_sum(cell->key, cell->value))
	{
		destroy_path();
		init_path();
	}
	if (!(cell = hash_find(bin, g_path)))
		return (PATH_NULL);
	*ret = cell->value;
	return (PATH_BIN);
}
