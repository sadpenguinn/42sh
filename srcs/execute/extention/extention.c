/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:56:17 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/23 21:03:05 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"
#include "extention.h"
#include <stdio.h>

int		get_len_of_name_var(char *str)
{
	int i;

	i = 0;
	while (str[i] != ' ' && str[i] && str[i] != '\'' && str[i] != '\"')
		i++;
	return (i);
}

int		get_len_of_dollar(char *str)
{
	int		i;
	int		counter;

	i = 1;
	counter = 0;
	if (!(str[i] == '{' || str[i] == '[' || str[i] == '('))
		return (get_len_of_name_var(str));
	while (str[i])
	{
		if (str[i] == '{' || str[i] == '[' || str[i] == '(')
			counter++;
		if (str[i] == '}' || str[i] == ']' || str[i] == ')')
			counter--;
		i++;
		if (!counter)
			break ;
	}
	if (counter)
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
	if (!res)
		return (NULL);
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
	free(res_to_replace);
	free(buf);
	return (res);
}

/*
**	fuck_norm[0] - len_of_extention
**	fuck_norm[1] - brackets
*/

char	**extention_with_split(char *str)
{
	char	*res;
	char	*buf;
	int		fuck_norm[3];
	int		i;
	int		j;

	res = xmalloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	j = 0;
	fuck_norm[1] = 0;
	fuck_norm[2] = 0;
	fuck_norm[0] = 0;
	while (str[i])
	{
		if (str[i] == '$' && !fuck_norm[1])
		{
			buf = get_pahom(&str[i], &i, &fuck_norm[0]);
			if (!buf)
			    return (NULL);
			res = remalloc_result_of_extention(str, res, buf, fuck_norm[0]);
			j += ft_strlen(buf);
		}
		else
		{
			if (str[i] == '\'' && !fuck_norm[2])
				fuck_norm[1] = (fuck_norm[1] + 1) % 2;
			if (str[i] == '\"' && !fuck_norm[1])
				fuck_norm[2] = (fuck_norm[2] + 1) % 2;
			res[j] = str[i];
			j++;
			i++;
		}
	}
	res[j] = '\0';
	return (strsplit_for_extention(res));
}

char	*extention(char *str)
{
	char	*res;
	char	*buf;
	int		fuck_norm[3];
	int		i;
	int		j;

	res = xmalloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	j = 0;
	fuck_norm[1] = 0;
	fuck_norm[2] = 0;
	fuck_norm[0] = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !fuck_norm[2])
		{
			fuck_norm[1] = (fuck_norm[1] + 1) % 2;
			i++;
		}
		else if (str[i] == '\"' && !fuck_norm[1])
		{
			fuck_norm[2] = (fuck_norm[2] + 1) % 2;
			i++;
		}
		else if (str[i] == '$' && !fuck_norm[1])
		{
			buf = get_pahom(&str[i], &i, &fuck_norm[0]);
            if (!buf)
                return (NULL);
			res = remalloc_result_of_extention(str, res, buf, fuck_norm[0]);
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

void	printmas(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		printf("str[%d] = %s\n", i, str[i]);
		free(str[i]);
		i++;
	}
	free(str);

}

int		main(int argc, char **argv, char **env)
{

	(void)argc;
	(void)argv;
	init_env(env);
	// hash_print(g_hash_env);
	// sgetenv("HOwqdqwME");
	//ssetenv("a", "a1 a2 a3 a4");
	char *res = extention("$HOME");
	free(res);
	//printmas(extention_with_split("\"$a\" 1 23"));
	return (0);
}
