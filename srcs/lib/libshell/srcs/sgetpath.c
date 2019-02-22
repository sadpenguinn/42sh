/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgetpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 22:40:17 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/22 21:01:12 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libshell.h"

char	*sgetpath(const char *bin)
{
	struct stat	stats;
	t_hshtb		*cell;
	t_hshtb		*cell2;
	char		*str;

	if (!(cell = hash_find(bin, g_path)))
		return (NULL);
	if (!(cell2 = hash_find(cell->data, g_path_sums)))
		return (NULL);
	if ((stat(cell->data, &stats) == -1))
		return (cell->value);
	str = ft_itoa(stats.st_mtimespec.tv_sec);
	if (!ft_strcmp(str, cell2->value))
	{
		ft_strdel(&str);
		return (cell->value);
	}
	ft_strdel(&str);
	destroy_path();
	init_path();
	if (!(cell = hash_find(bin, g_path)))
		return (NULL);
	return (cell->value);
}
