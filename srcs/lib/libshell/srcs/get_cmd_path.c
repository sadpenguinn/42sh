/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:41:09 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/28 20:16:11 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libshell.h"
#include "execute.h"

/*
** Extends functionality of sgetpath, handling path to binaries like '/bin/ls'
*/

static int	find_abs_bin(char *name, void **ret)
{
	if (!(access(name, X_OK)))
	{
		*ret = name;
		return (PATH_BIN);
	}
	if ((access(name, F_OK)))
	{
		sputcmderr(sstrerr(SHERR_CMNDNTF), "42sh", name);
		return (PATH_NULL);
	}
	sputcmderr(sstrerr(SHERR_PERMDEN), "42sh", name);
	return (PATH_NULL);
}

static int 	find_function(char *name, void **ret)
{
	t_func	*function;
	size_t	size;
	size_t	i;

	i = 0;
	size = vector_get_len(g_func);
	while (i < size)
	{
		function = (t_func *)vector_get_elem(g_func, i);
		if (!ft_strcmp(function->name, name))
		{
			*ret = function->func;
			return (PATH_FUNC);
		}
		i++;
	}
	return (PATH_NULL);
}

int			get_cmd_path(char *str, void **ret)
{
	int		tmp;

	if (ft_strchr(str, '/'))
		return (find_abs_bin(str, ret));
	else if ((tmp = find_function(str, ret)) != PATH_NULL)
		return (tmp);
	else
	{
		tmp = sgetpath(str, ret);
		if (tmp == PATH_NULL)
		{
			sputcmderr(sstrerr(SHERR_CMNDNTF), "42sh", str);
			return (PATH_NULL);
		}
		return (tmp);
	}
}
