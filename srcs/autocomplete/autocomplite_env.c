/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:29:40 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/09 06:47:38 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int		get_mas_env_autocompl_len(char *str)
{
	int i;
	int	counter;

	i = 0;
	counter = 0;
	while (g_env.env[i])
	{
		if (!(ft_strncmp(g_env.env[i], str, ft_strlen(str))))
			counter++;
		i++;
	}
	return (counter);
}

char	**get_mas_env_autocompl(char *str)
{
	char	**res;
	int		counter;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(counter = get_mas_env_autocompl_len(str)))
		return (NULL);
	res = xmalloc(sizeof(char **) * (counter + 1));
	while (g_env.env[i])
	{
		if (!(ft_strncmp(g_env.env[i], str, ft_strlen(str))))
		{
			res[j] = ft_strndup(g_env.env[i], ft_strchr(g_env.env[i], '=')
								- g_env.env[i]);
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
