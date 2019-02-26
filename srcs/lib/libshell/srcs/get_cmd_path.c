/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:41:09 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/26 20:24:34 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libshell.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_cmd_path(char *str)
{
	char	*tmp;

	if (ft_strchr(str, '/'))
	{
		if (!(access(str, X_OK)))
			return (str);
		if ((access(str, F_OK)))
		{
			ft_putstr_fd("No such file or directory\n", 2);
			return (NULL);
		}
		ft_putstr_fd("Permission denied\n", 2);
		return (NULL);
	}
	else
	{
		tmp = sgetpath(str);
		if (!tmp)
		{
			ft_putstr_fd("No such command\n", 2);
			return (NULL);
		}
		return (tmp);
	}
}
