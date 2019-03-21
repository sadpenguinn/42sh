/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:45:31 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/21 12:30:08 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

static char		*validation_brackets(char *str)
{
	int		len;
	char	*res;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (!(str[0] == '[' && str[1] == ' ' && 
		str[len - 1] == ']') && str[len - 2] == ' ')
		return (NULL);
	res = ft_strndup(&str[2], len - 3);
	printf("res = |%s|\n", res);
	free(str);
	return (res);
}

static int		ft_word_count(char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		while (ft_isspace(*s) && *s)
			s++;
		if (*s)
			count++;
		while (!ft_isspace(*s) && *s)
			s++;
	}
	return (count);
}

static char		*ft_word_cpy(char **s)
{
	int		len;
	char	*str;
	char	*rtn;

	while (ft_isspace(**s))
		(*s)++;
	len = 0;
	while ((*s)[len] && ft_isspace((*s)[len]))
		len++;
	if ((str = (char *)xmalloc(sizeof(char) * (len + 1))) == (char *)0)
		return ((char *)0);
	rtn = str;
	while (**s && !ft_isspace(**s))
		*str++ = *(*s)++;
	*str = 0;
	return (rtn);
}

char			**strsplit_to_conditions(char *str)
{
	int		i;
	int		count;
	char	**split;

	if (!(str = validation_brackets(str)))
		return (NULL);
	count = ft_word_count(str);
	if ((split = (char **)xmalloc(sizeof(char *) * (count + 1))) == (char **)0)
		return ((char **)0);
	split[count] = (char *)0;
	i = 0;
	while (i < count)
		split[i++] = ft_word_cpy(&str);
	return (split);
}
