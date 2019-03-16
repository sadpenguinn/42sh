/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_processings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 22:04:35 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/16 21:29:13 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

void		expand_backslash_handling(char **str, int is_free)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = xmalloc(sizeof(char) * (ft_strlen(*str) + ft_strchrc(*str, ' ') + 1));
	while ((*str)[i])
	{
		if ((*str)[i] != '\\')
		{
			res[j] = (*str)[i];
			i++;
			j++;
		}
		else
			i++;
	}
	if (is_free)
		free(*str);
	*str = res;
}

char		*pre_processing_in_expand(int *f_n, char **str, int *i, int *j)
{
	expand_backslash_handling(str, 0);
	processing_stars(str);
	frashing_values(f_n, i, j);
	return (xmalloc(sizeof(char) * (ft_strlen(*str) + 1)));
}

char		*pre_processing_in_expand_v(int *f_n, char **str, int *i, int *j)
{
	processing_stars(str);
	frashing_values(f_n, i, j);
	return (xmalloc(sizeof(char) * (ft_strlen(*str) + 1)));
}
