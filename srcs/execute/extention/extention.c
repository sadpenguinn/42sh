/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:56:17 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/19 18:28:39 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "../execute.h"
#include "extention.h"
#include <stdio.h>

int		get_len_of_dollar(char *str)
{
	int		i;
	int		counter;
	int		var;

	i = 1;
	counter = 0;
	var = (str[i] == '{' || str[i] == '[' || str[i] == '(') ? 0 : 1;
	while (str[i] && !(var && str[i] == ' '))
	{
		if (str[i] == '{' || str[i] == '[' || str[i] == '(')
			counter++;
		if (str[i] == '}' || str[i] == ']' || str[i] == ')')
			counter--;
		i++;
		if (!counter)
			break ;
	}
	if (!var && counter)
	{
		ft_putstr("invalid syntax!\n");
		exit(0);
	}
	return (i);
}

char	*get_pahom(char *str, int *i, int *len_of_expression)
{
	char	*res;

	*len_of_expression = get_len_of_dollar(str);
	*i += *len_of_expression;
	res = get_content_of_expression(ft_strndup(str, *len_of_expression));
	return (res);
}

char	*remalloc_result_of_extention(char *res_to_count, char *res_to_replace,
										char *buf, int n)
{
	char	*res;

	printf("buf = %s\n", buf);
	res = xmalloc(sizeof(char) *
					(ft_strlen(res_to_count) - n + ft_strlen(buf) + 1));
	printf("buf = %s\n", buf);
	ft_strcpy(res, res_to_replace);
	ft_strcat(res, buf);
	return (res);
}

char	*extention(char *str)
{
	char	*res;
	char	*buf;
	int		len_of_extention;
	int		i;
	int		j;

	res = xmalloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			buf = get_pahom(&str[i], &i, &len_of_extention);
			res = remalloc_result_of_extention(str, res, buf, len_of_extention);
			j += ft_strlen(buf);
		}
		else
		{
			res[j] = str[i];
			j++;
			i++;
		}
	}
	res[j] = '\0';
	return (res);
}

int		main(void)
{
	printf("Result = %s\n", extention("check ${parameter#par} check"));
	return (0);
}
