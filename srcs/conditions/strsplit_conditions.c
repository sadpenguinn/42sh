/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:45:31 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/22 20:08:53 by bbaelor-         ###   ########.fr       */
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
	if (len - 4 < 1)
		return (0);
	res = ft_strndup(&str[2], len - 4);
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
	str = (char *)xmalloc(sizeof(char) * (len + 1));
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
	{
		free(str);
		return (NULL);
	}
	split = ft_strsplit(str, ' ');
	free(str);
	return (split);
	count = ft_word_count(str);
	split = (char **)xmalloc(sizeof(char *) * (count + 1));
	split[count] = (char *)0;
	i = 0;
	while (i < count)
		split[i++] = ft_word_cpy(&str);
	return (split);
}
