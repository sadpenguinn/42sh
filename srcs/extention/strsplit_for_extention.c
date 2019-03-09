/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit_for_extention.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:11:06 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/01 20:58:53 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

static int		count_words(char *str)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1])
		{
			count++;
			i++;
		}
		else if (str[i] == '\'')
			brackets_case_in_strsplit(str, &i, '\'');
		else if (str[i] == '\"')
			brackets_case_in_strsplit(str, &i, '\"');
		else
			i++;
	}
	return (str[0] ? count : 0);
}

static int		count_word(char *str)
{
	int i;

	i = 0;
	while (str[i] != ' ' && str[i])
	{
		if (str[i] == '\'')
		{
			i += 2;
			while (str[i - 1] && str[i - 1] != '\'')
				i++;
		}
		else if (str[i] == '\"')
		{
			i += 2;
			while (str[i - 1] && str[i - 1] != '\"')
				i++;
		}
		else
			i++;
	}
	return (i);
}

static int		ft_strcpy_extention(char *copy_to, char *copy_from)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (copy_from[i])
	{
		if (copy_from[i] == '\'' || copy_from[i] == '\"')
			i++;
		else
		{
			copy_to[j] = copy_from[i];
			i++;
			j++;
		}
	}
	free(copy_from);
	return (i);
}

static int		filling_strings(char *str, int i, int j, char **res)
{
	while (str[i])
	{
		if (str[i] != ' ')
		{
			res[j] = (char *)xmalloc(sizeof(char *) * count_word(&str[i]));
			i += ft_strcpy_extention(res[j], ft_strndup(&str[i],
										count_word(&str[i])));
			j++;
		}
		else
			i++;
	}
	return (j);
}

char			**strsplit_for_extention(char *str)
{
	int		i;
	int		j;
	char	**res;

	res = xmalloc(sizeof(char **) * (count_words(str) + 1));
	i = 0;
	j = 0;
	if (count_words(str) == 1)
	{
		while (str[i] && str[i] == ' ')
			i++;
		res[j] = xmalloc(sizeof(char *) * count_word(&str[i]));
		i += ft_strcpy_extention(res[j], ft_strdup(&str[i]));
		j++;
	}
	else
		j = filling_strings(str, i, j, res);
	res[j] = NULL;
	free(str);
	return (res);
}
