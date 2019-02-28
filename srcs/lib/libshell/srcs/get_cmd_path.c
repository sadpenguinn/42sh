/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:41:09 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/28 14:56:10 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libshell.h"

/*
** Extends functionality of sgetpath, handling path to binaries like '/bin/ls'
*/

int		get_cmd_path(char *str, void **ret)
{
	int		tmp;

	if (ft_strchr(str, '/'))
	{
		if (!(access(str, X_OK)))
		{
			*ret = str;
			return (PATH_BIN);
		}
		if ((access(str, F_OK)))
		{
			ft_putstr_fd("No such file or directory\n", 2);
			return (PATH_NULL);
		}
		ft_putstr_fd("Permission denied\n", 2);
		return (PATH_NULL);
	}
	else
	{
		tmp = sgetpath(str, ret);
		if (tmp == PATH_NULL)
		{
			ft_putstr_fd("No such command\n", 2);
			return (PATH_NULL);
		}
		return (tmp);
	}
}
