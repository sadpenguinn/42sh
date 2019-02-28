/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 04:33:35 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/28 04:43:23 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

char			*get_string_from_tab(char **str)
{
	int		i;
	int		len;
	char	*res;

	len = 0;
	i = 0;
	while (str[i])
	{
		len += ft_strlen(str[i]) + 1;
		i++;
	}
	res = xmalloc(sizeof(char) * (len + 1));
	i = 0;
	while (str[i])
	{
		ft_strcat(res, str[i]);
		if (str[i + 1])
			ft_strcat(res, " ");
		i++;
	}
	return (res);
}

static int		remalloc_result_of_glob(char **str, char **res_glob,
										int i, int begin)
{
	char	*res;
	char	*just_string;
	char	*buf;
	int		to_return;

	just_string = get_string_from_tab(res_glob);
	res = xmalloc(sizeof(char) * ((ft_strlen(*str) + ft_strlen(just_string))));
	buf = ft_strndup(*str, begin);
	ft_strcat(res, buf);
	ft_strcat(res, just_string);
	to_return = ft_strlen(res);
	ft_strcat(res, &(*str)[i + 1]);
	free(buf);
	free(just_string);
	*str = res;
	return (to_return);
}

static int		get_result_of_glob(char **str, char *code, int n, int begin)
{
	int		i;
	int		dump_path;
	int		state;
	char	**pre_result;

	state = 0;
	i = 0;
	dump_path = -1;
	while (code[i] && code[i] != ' ')
	{
		if (code[i] == '*')
			state = 1;
		if (code[i] == '/' && !state)
			dump_path = i;
		i++;
	}
	if (dump_path == -1)
		state = xglob(ft_strndup(code, i), ".", &pre_result,
						(size_t *)&dump_path);
	else
		state = xglob(ft_strndup(&code[dump_path + 1], i), ft_strndup(*str,
						dump_path + 1), &pre_result, (size_t *)&dump_path);
	if (state || !pre_result || !pre_result[0])
		return (n);
	return (remalloc_result_of_glob(str, pre_result, n, begin));
}

void			processing_stars(char **str)
{
	int		brackets[2];
	int		i;
	int		counter;

	ft_bzero(brackets, sizeof(int) * 2);
	i = 0;
	counter = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\'' && !brackets[1])
			brackets[0] = (brackets[0] + 1) % 2;
		if ((*str)[i] == '\"' && !brackets[0])
			brackets[1] = (brackets[1] + 1) % 2;
		if ((*str)[i] == '*' && !brackets[0] && !brackets[1])
			i += get_result_of_glob(str, &(*str)[i - counter], i, i - counter);
		else if ((*str)[i] != ' ')
			counter++;
		else
			counter = 0;
		i++;
	}
}
