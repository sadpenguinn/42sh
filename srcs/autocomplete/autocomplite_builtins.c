/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite_builtins.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:27:22 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/09 06:41:39 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int		get_autocomplite_built_in_mas_len(char *str)
{
	int		i;
	size_t	len_word;
	int		counter;

	counter = 0;
	len_word = ft_strlen(str);
	i = 0;
	while (g_built_in_lists[i])
	{
		if (!ft_strncmp(str, g_built_in_lists[i], len_word))
			counter++;
		i++;
	}
	return (counter);
}

char	**get_autocomplite_built_in_mas(char *str, char **res, int *c)
{
	int		i;
	size_t	len_word;

	len_word = ft_strlen(str);
	i = 0;
	while (g_built_in_lists[i])
	{
		if (!ft_strncmp(str, g_built_in_lists[i], len_word))
		{
			res[*c] = ft_strdup(g_built_in_lists[i]);
			(*c)++;
		}
		i++;
	}
	return (res);
}
