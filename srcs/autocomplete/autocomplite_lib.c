/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite_lib.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 03:49:55 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/16 23:38:01 by bbaelor-         ###   ########.fr       */
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

char	*ft_strlastchr(char *str, char c)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			tmp = &(str[i]);
		i++;
	}
	return (tmp);
}

char	*atcml_get_pattern(char *buf, int pos)
{
	char	*pattern;
	char	*tmp;
	int		l_p;
	int		check;

	check = 1;
	l_p = pos;
	while (l_p > 0 && check)
	{
		if ((buf[l_p - 1] == ' ' || buf[l_p - 1] == '/') && 
						(!(l_p - 1) || buf[l_p - 2] != '\\'))
			check = 0;
		else
			l_p--;
	}
	tmp = ft_strndup(buf + l_p, pos - l_p);
	expand_backslash_handling(&tmp, 1);
	pattern = ft_strjoin(tmp, "*", 1);
	return (pattern);
}

// char	*atcml_get_rel_dir(char *buf, int pos)
// {
// 	size_t	left_pos;
// 	char	*tmp;

// 	if (!(ft_strchr(buf, '/')))
// 		return (ft_strdup("./"));
// 	if (pos)
// 		pos--;
// 	while (pos && buf[pos] != '/' && buf[pos - 1] != ' ')
// 		pos--;
// 	if (pos && buf[pos - 1] == ' ' && (pos - 1) && buf[pos - 2] == '\\')
// 	{
// 		pos--;
// 		while (pos && buf[pos] != '/' && buf[pos - 1] != ' ')
// 			pos--;
// 	}
// 	left_pos = pos;
// 	while (left_pos && buf[left_pos - 1] != ' ')
// 		left_pos--;
// 	if (left_pos && buf[left_pos - 1] == ' ' && (left_pos - 1) && buf[left_pos - 2] == '\\')
// 	{
// 		left_pos--;
// 		while (left_pos && buf[left_pos - 1] != ' ')
// 			left_pos--;
// 	}
// 	tmp = ft_strndup(buf + left_pos, pos - left_pos + 1);
// 	expand_backslash_handling(&tmp, 1);
// 	return (tmp);
// }

char	*atcml_get_rel_dir(char *buf, int pos)
{
	char	*last;
	char	*tmp;

	if (pos)
		pos--;
	if (!(ft_strchr(buf, '/')))
		return (ft_strdup("./"));
	last = ft_strlastchr(buf, '/');
	while (pos >= 0 && buf[pos])
	{
		if (buf[pos] == ' ' && (!pos || buf[pos - 1] != '\\'))
		{
			tmp = ft_strjoin(ft_strndup(&buf[pos], last - &buf[pos]), "/", 1);
			expand_backslash_handling(&tmp, 1);
			return (tmp);
		}
		pos--;
	}
	tmp = ft_strjoin(ft_strndup(buf, last - buf), "/", 1);
	expand_backslash_handling(&tmp, 1);
	return (tmp);
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
