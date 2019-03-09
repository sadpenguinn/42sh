/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite_lib.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 03:49:55 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/09 06:41:07 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

char	*ft_strendchr(char *str, char c)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (str[i])
	{
		if (str[i] == c)
			res = &str[i];
		i++;
	}
	return (res);
}

char	*atcml_get_pattern(char *buf, size_t pos)
{
	char	*pattern;
	char	*tmp;
	size_t	left_pos;

	left_pos = pos;
	while (left_pos && buf[left_pos - 1] != ' ' && buf[left_pos - 1] != '/')
		left_pos--;
	tmp = ft_strndup(buf + left_pos, pos - left_pos);
	pattern = ft_strjoin(tmp, "*", 0);
	free(tmp);
	return (pattern);
}

char	*atcml_get_rel_dir(char *buf, size_t pos)
{
	size_t	left_pos;

	if (!(ft_strchr(buf, '/')))
		return (ft_strdup("./"));
	if (pos)
		pos--;
	while (pos && buf[pos] != '/' && buf[pos - 1] != ' ')
		pos--;
	left_pos = pos;
	while (left_pos && buf[left_pos - 1] != ' ')
		left_pos--;
	return (ft_strndup(buf + left_pos, pos - left_pos + 1));
}

char	**tab_cat(char **to_str, char **from_str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!from_str)
		return (to_str);
	while (to_str[i])
		i++;
	while (from_str[j])
	{
		to_str[i] = from_str[j];
		i++;
		j++;
	}
	to_str[i] = NULL;
	return (to_str);
}
