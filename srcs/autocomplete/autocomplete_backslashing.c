/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_backslashing.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 09:59:10 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/20 12:36:04 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

char		*autocomplite_backsl_str(char *str)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	res = xmalloc(sizeof(char) * (ft_strlen(str) + 1 +
													(UL)ft_strchrc(str, ' ')));
	while (str[i])
	{
		if (str[i] == ' ')
		{
			res[j] = '\\';
			j++;
		}
		res[j] = str[i];
		i++;
		j++;
	}
	free(str);
	return (res);
}

char		**autocomplite_get_backslashing(char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if ((tmp = ft_strchr(str[i], ' ')) && tmp[1])
			str[i] = autocomplite_backsl_str(str[i]);
		i++;
	}
	return (str);
}
