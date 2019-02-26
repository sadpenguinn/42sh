/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_remalloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:42:41 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/26 19:13:54 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

int		get_len_of_name_var(char *str)
{
	int i;

	i = 0;
	while (str[i] != ' ' && str[i] && str[i] != '\'' && str[i] != '\"')
		i++;
	return (i);
}

int		get_len_of_path(char *str)
{
	int i;

	i = 1;
	if (!str[1] || str[i] == '/' || str[1] == ' ')
		return (1);
	while (str[i] && str[i] != '/' && str[i] != ' ')
		i++;
	return (i);
}

int		get_len_of_dollar(char *str)
{
	int		i;
	int		counter;

	i = 1;
	counter = 0;
	if (str[0] == '~')
		return (get_len_of_path(str));
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
		ft_putstr_fd("42sh: invalid syntax!\n", 2);
		return (-1);
	}
	return (i);
}

char	*get_pahom(char *str, int *i, int *len_of_expression)
{
	char	*res;

	*len_of_expression = get_len_of_dollar(str);
	if (*len_of_expression == -1)
		return (NULL);
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

	res = xmalloc(sizeof(char) *
					(ft_strlen(res_to_count) - n + ft_strlen(buf) + 1));
	ft_strcpy(res, res_to_replace);
	ft_strcat(res, buf);
	free(res_to_replace);
	return (res);
}
