/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:45:31 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/26 02:24:25 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

// static char		*validation_brackets(char *str)
// {
// 	int		len;
// 	char	*res;

// 	if (!str)
// 		return (NULL);
// 	len = ft_strlen(str);
// 	if (!(str[0] == '[' && str[1] == ' ' &&
// 		str[len - 1] == ']') && str[len - 2] == ' ')
// 		return (NULL);
// 	if (len - 4 < 1)
// 		return (0);
// 	res = ft_strndup(&str[2], len - 4);
// 	printf("res = |%s|\n", res);
// 	free(str);
// 	return (res);
// }

// static int		ft_word_count(char *s)
// {
// 	int count;

// 	count = 0;
// 	while (*s)
// 	{
// 		while (ft_isspace(*s) && *s)
// 			s++;
// 		if (*s)
// 			count++;
// 		while (!ft_isspace(*s) && *s)
// 			s++;
// 	}
// 	return (count);
// }

// static char		*ft_word_cpy(char **s)
// {
// 	int		len;
// 	char	*str;
// 	char	*rtn;

// 	while (ft_isspace(**s))
// 		(*s)++;
// 	len = 0;
// 	while ((*s)[len] && ft_isspace((*s)[len]))
// 		len++;
// 	str = (char *)xmalloc(sizeof(char) * (len + 1));
// 	rtn = str;
// 	while (**s && !ft_isspace(**s))
// 		*str++ = *(*s)++;
// 	*str = 0;
// 	return (rtn);
// }

static void		free_mas(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char		**rewriting_mas(char **str, int len)
{
	int		i;
	char	**res;

	len--;
	res = xmalloc(sizeof(char *) * len);
	i = 1;
	free(str[0]);
	while (i < len)
	{
		res[i - 1] = expand(str[i]);
		// printf("Записал в res[%d] = |%s|\n", i - 1, res[i - 1]);
		free(str[i]);
		i++;
	}
	free(str[i]);
	res[i - 1] = NULL;
	free(str);
	return (res);
}

char			**strsplit_to_conditions(char *str)
{
	char	**res;
	int		i;

	i = 0;
	// printf("get string %s\n", str);
	res = ft_strsplit(str, ' ');
	while (res[i])
	{
		// printf("res[%d] = |%s|\n", i, res[i]);
		i++;
	}
	if (!res)
	{
		free(str);
		return (NULL);
	}
	if (ft_strcmp(res[0], "[") || ft_strcmp(res[i - 1], "]"))
	{
		free_mas(res);
		free(str);
		return (NULL);
	}
	res = rewriting_mas(res, i);
	return (res);
}
