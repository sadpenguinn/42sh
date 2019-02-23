/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:41:48 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static char		*ft_word_cpy(char const **s, char c)
{
	int		len;
	char	*str;
	char	*rtn;

	while (**s == c)
		(*s)++;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	if ((str = (char *)xmalloc(sizeof(char) * (len + 1))) == (char *)0)
		return ((char *)0);
	rtn = str;
	while (**s && **s != c)
		*str++ = *(*s)++;
	*str = 0;
	return (rtn);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		count;
	char	**split;

	if (!s)
		return ((char **)0);
	count = ft_word_count(s, c);
	if ((split = (char **)xmalloc(sizeof(char *) * (count + 1))) == (char **)0)
		return ((char **)0);
	split[count] = (char *)0;
	i = 0;
	while (i < count)
		split[i++] = ft_word_cpy(&s, c);
	return (split);
}
