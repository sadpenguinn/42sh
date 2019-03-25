/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_files_or_dirs.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:06:24 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/20 12:23:30 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

char		**get_only_fi_autocompile_len(char *str, int *count)
{
	int		i;
	int		c;
	char	**res;

	c = 0;
	if (!(res = get_only_fi_di_autocompile(str)))
		return (NULL);
	i = 0;
	while (res[i])
	{
		if (res[i][ft_strlen(res[i]) - 1] == ' ')
			c++;
		i++;
	}
	*count = c;
	return (res);
}

char		**get_only_fi_autocompile(char *str)
{
	int		i;
	int		j;
	int		c;
	char	**all;
	char	**res;

	j = 0;
	i = 0;
	if (!(all = get_only_fi_autocompile_len(str, &c)))
		return (NULL);
	res = xmalloc(sizeof(char *) * (UL)(c + 1));
	while (all[i])
	{
		if (all[i][ft_strlen(all[i]) - 1] == ' ')
		{
			res[j] = ft_strdup(all[i]);
			j++;
		}
		free(all[i]);
		i++;
	}
	free(all);
	res[j] = NULL;
	return (res);
}

static char	**get_only_dir_autocompile_len(char *str, int *count)
{
	int		i;
	int		c;
	char	**res;

	c = 0;
	if (!(res = get_only_fi_di_autocompile(str)))
		return (NULL);
	i = 0;
	while (res[i])
	{
		if (res[i][ft_strlen(res[i]) - 1] == '/')
			c++;
		i++;
	}
	*count = c;
	return (res);
}

char		**get_only_dir_autocompile(char *str)
{
	int		i;
	int		j;
	int		c;
	char	**all;
	char	**res;

	j = 0;
	i = 0;
	if (!(all = get_only_dir_autocompile_len(str, &c)))
		return (NULL);
	res = xmalloc(sizeof(char *) * (UL)(c + 1));
	while (all[i])
	{
		if (all[i][ft_strlen(all[i]) - 1] == '/')
		{
			res[j] = ft_strdup(all[i]);
			j++;
		}
		free(all[i]);
		i++;
	}
	free(all);
	res[j] = NULL;
	return (res);
}
