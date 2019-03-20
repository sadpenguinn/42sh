/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beautifylizing_flags_output.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 09:52:41 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/20 12:44:44 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

char	*autocomplete_beautifulizing_string(char *str, size_t max)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	res = xmalloc(sizeof(char) * (ft_strlen(str) + max + 1));
	while (str[i] != '[')
	{
		res[j] = str[i];
		i++;
		j++;
	}
	while (j <= max)
	{
		res[j] = ' ';
		j++;
	}
	ft_strcpy(&res[j], &str[i]);
	free(str);
	return (res);
}

char	**autocomplete_beautifulizing_mas(char **str)
{
	size_t		i;
	size_t		max;
	size_t		i_tmp;

	i = 0;
	max = 0;
	while (str[i])
	{
		i_tmp = (UL)(ft_strchr(str[i], '[') - str[i]);
		if (max < i_tmp)
			max = i_tmp;
		i++;
	}
	i = 0;
	while (str[i])
	{
		str[i] = autocomplete_beautifulizing_string(str[i], max);
		i++;
	}
	return (str);
}
