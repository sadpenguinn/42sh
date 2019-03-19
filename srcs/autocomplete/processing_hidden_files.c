/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_hidden_files.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:05:07 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/19 15:53:50 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

static int	check_point(char *str)
{
	str = atcml_get_pattern(str, ft_strlen(str));
	if (str && str[0] == '.')
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}

static int	processing_hidden_files_len(char **res)
{
	int	i;
	int counter;

	i = 0;
	counter = 0;
	while (res[i])
	{
		if (res[i][0] != '.')
			counter++;
		i++;
	}
	return (counter);
}

char		**processing_hidden_files(char **all, char *str)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	if (!(check_point(str)))
		return (all);
	res = xmalloc(sizeof(char *) * (processing_hidden_files_len(all) + 1));
	while (all[i])
	{
		if (all[i] && all[i][0] && all[i][0] != '.')
		{
			res[j] = ft_strdup(all[i]);
			j++;
		}
		free(all[i]);
		i++;
	}
	res[j] = NULL;
	free(all);
	return (res);
}
