/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 04:33:35 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/26 00:08:18 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

static int		remalloc_result_of_glob(char **str, char **res_glob,
										int i, int begin)
{
	char	*res;
	char	*just_string;
	char	*buf;
	int		to_return;

	just_string = get_string_from_tab_after_xglob(res_glob);
	res = xmalloc(sizeof(char) * ((ft_strlen(*str) + ft_strlen(just_string))));
	buf = ft_strndup(*str, begin);
	ft_strcat(res, buf);
	ft_strcat(res, just_string);
	to_return = ft_strlen(res);
	ft_strcat(res, &(*str)[i + 1]);
	free(buf);
	free(just_string);
	free(*str);
	*str = res;
	return (to_return);
}

static int		counter_for_get_res_glob(const char *code,
											int state, int i, int *dump_path)
{
	while (code[i] && code[i] != ' ')
	{
		if (code[i] == '*')
			state = 1;
		if (code[i] == '/' && !state)
			(*dump_path) = (i);
		i++;
	}
	return (i);
}

static int		get_result_of_glob(char **str, char *code, int n, int begin)
{
	int		i;
	int		dump_path;
	int		state;
	char	**pre_result;
	char	*tmp;

	state = 0;
	i = 0;
	dump_path = -1;
	i = counter_for_get_res_glob(code, state, i, &dump_path);
	if (dump_path == -1)
		state = xglob(
		(tmp = ft_strndup(code, i)), ".", &pre_result, (size_t *)&dump_path);
	else
		state = xglob(
			(tmp = ft_strndup(&code[dump_path + 1], i)),
			ft_strndup(*str, dump_path + 1), &pre_result, (size_t *)&dump_path);
	free(tmp);
	if (state || !pre_result || !pre_result[0])
	{
		if (!pre_result[0])
			free(pre_result);
		return (n);
	}
	return (remalloc_result_of_glob(str, pre_result, n, begin));
}

static int		get_len_of_subex(char *str)
{
	if (str[0] != '$')
		return (0);
	if (str[0] == '*')
		return (0);
	return (get_len_of_dollar(str));
}

void			processing_stars(char **str)
{
	int		brackets[2];
	size_t	i;
	size_t	len;
	size_t	counter;

	ft_bzero(brackets, sizeof(int) * 2);
	i = 0;
	counter = 0;
	len = ft_strlen(*str);
	while (i < len && (*str)[i])
	{
		i += get_len_of_subex(&((*str)[i]));
		if ((*str)[i] == '\'' && !brackets[1])
			brackets[0] = (brackets[0] + 1) % 2;
		if ((*str)[i] == '\"' && !brackets[0])
			brackets[1] = (brackets[1] + 1) % 2;
		if ((*str)[i] == '*' && !brackets[0] && !brackets[1])
			i += get_result_of_glob(str, &(*str)[i - counter], (int)i,
															(int)(i - counter));
		else if ((*str)[i] != ' ')
			counter++;
		else
			counter = 0;
		i++;
	}
}
