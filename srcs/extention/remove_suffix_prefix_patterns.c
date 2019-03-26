/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_suffix_prefix_patterns.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 19:15:58 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/26 17:14:23 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "extention.h"

static char	*get_resl_pattern(char *str)
{
	int		i;
	int		count;
	char	*res;

	i = 0;
	count = 0;
	while (str[i] != '#' && str[i] != '%')
		i++;
	while (str[i] && str[i] != '}')
	{
		i++;
		count++;
	}
	res = ft_strndup(&str[i - count + 1], ft_strlen(&str[i - count + 1]) - 1);
	return (res);
}

char	*remove_smallest_suffix_pattern(char *str)
{
	char	*tmp;
	char	*pattern;
	int		i;
	char	*res;

	i = 0;
	while (str[i] != '%')
		i++;
	tmp = ft_strndup(str, i);
	res = get_content_of_var(&tmp[2]);
	pattern = get_resl_pattern(str);
	if (!res || ft_strlen(res) < ft_strlen(pattern))
	{
		free(tmp);
		free(pattern);
		return (ft_strdup(""));
	}
	res = ft_strdup(res);
	if (!(ft_strcmp(pattern, &res[ft_strlen(res) - ft_strlen(pattern)])))
		res[ft_strlen(res) - ft_strlen(pattern)] = '\0';
	free(tmp);
	free(pattern);
	return (res);
}

char	*remove_smallest_prefix_pattern(char *str)
{
	char	*tmp;
	char	*pattern;
	int		i;
	char	*res;

	i = 0;
	while (str[i] != '#')
		i++;
	tmp = ft_strndup(str, i);
	res = get_content_of_var(&tmp[2]);
	pattern = get_resl_pattern(str);
	if (!res || ft_strlen(res) < ft_strlen(pattern))
	{
		free(tmp);
		free(pattern);
		return (ft_strdup(""));
	}
	if (!(ft_strncmp(pattern, res, ft_strlen(pattern))))
		res = ft_strdup(&res[ft_strlen(pattern)]);
	else
		res = ft_strdup(res);	
	free(tmp);
	free(pattern);
	return (res);
}
