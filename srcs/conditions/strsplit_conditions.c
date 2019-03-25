/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:45:31 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/26 02:57:38 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

static void		free_mas(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char		**rewriting_mas(char **str, int len)
{
	int		i;
	char	**res;

	len--;
	res = xmalloc(sizeof(char *) * len);
	i = 1;
	free(str[0]);
	while (i < len)
	{
		res[i - 1] = expand(str[i]);
		free(str[i]);
		i++;
	}
	free(str[i]);
	res[i - 1] = NULL;
	free(str);
	return (res);
}

char			**strsplit_to_conditions(char *str)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_strsplit(str, ' ');
	while (res[i])
		i++;
	if (!res)
	{
		free(str);
		return (NULL);
	}
	if (ft_strcmp(res[0], "[") || ft_strcmp(res[i - 1], "]"))
	{
		free_mas(res);
		free(str);
		return (NULL);
	}
	res = rewriting_mas(res, i);
	return (res);
}
