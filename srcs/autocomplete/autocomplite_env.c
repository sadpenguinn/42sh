/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:29:40 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/20 13:29:34 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

size_t	get_mas_env_autocompl_len(char *str)
{
	size_t	i;
	size_t	counter;

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
	size_t	counter;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(counter = get_mas_env_autocompl_len(str)))
		return (NULL);
	res = xmalloc(sizeof(char **) * (counter + 1));
	while (g_env.env[i])
	{
		if (!(ft_strncmp(g_env.env[i], str, ft_strlen(str))))
		{
			res[j] = ft_strndup(g_env.env[i], (UL)(ft_strchr(g_env.env[i], '=') - g_env.env[i]));
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
