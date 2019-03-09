/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_suffix_prefix_patterns.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 19:15:58 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/01 20:40:49 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "extention.h"

char	*remove_smallest_suffix_pattern(char *str)
{
	char	*tmp;
	char	*pattern;
	int		i;
	char	*res;
	char	*to_check;

	i = 0;
	while (str[i] != '%')
		i++;
	tmp = ft_strndup(str, i);
	res = get_content_of_var(&tmp[2]);
	if (!res)
		return (ft_strdup(""));
	pattern = ft_strndup(&str[i + 1], ft_strlen(&str[i + 3]) + 1);
	to_check = get_last_n_symbols(res, ft_strlen(pattern), 0);
	if (pattern && pattern[0] && !ft_strcmp(pattern, to_check))
		return (ft_strndup(res, ft_strlen(res) - ft_strlen(pattern)));
	return (ft_strdup(res));
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
	if (!res)
		return (ft_strdup(""));
	pattern = ft_strndup(&str[i + 1], ft_strlen(&str[i + 3]) + 1);
	if (pattern && pattern[0] && !ft_strncmp(res, pattern, ft_strlen(pattern)))
		return (ft_strdup(&res[ft_strlen(pattern)]));
	return (ft_strdup(res));
}
