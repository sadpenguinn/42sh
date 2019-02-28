/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:30:34 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/28 03:43:27 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

void	frashing_values(int *fuck_norm, int *i, int *j)
{
	(*i) = 0;
	(*j) = 0;
	fuck_norm[1] = 0;
	fuck_norm[2] = 0;
	fuck_norm[0] = 0;
}

/*
**	fuck_norm[0] - len_of_extention
**	fuck_norm[1] - ''
**  fuck_norm[2] - ""
*/

static int	tilda_case_check(char *str, int i)
{
	if (str[i] == '~')
	{
		if (i == 0)
			return (1);
		else if (str[i - 1] == ' ')
			return (1);	
	}
	return (0);
}

char	*get_string_from_tab(char **str)
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

int		remalloc_result_of_glob(char **str, char **res_glob, int i, int begin)
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

int		get_result_of_glob(char **str, char *code, int n, int begin)
{
	int		i;
	int		dump_path;
	int		state;
	char	**pre_result;

	i = 0;
	dump_path = -1;
	while (code[i] && code[i] != ' ')
	{
		if (code[i] == '/')
			dump_path = i;
		i++;
	}
	if (dump_path == -1)
		state = xglob(ft_strndup(code, i), ".", &pre_result, (size_t *)&dump_path);
	else
		state = xglob(ft_strndup(&code[dump_path + 1], i), ft_strndup(*str, dump_path + 1), &pre_result, (size_t *)&dump_path);
	if (!pre_result || !pre_result[0])
		return (n);
	if (state)
		return (n);
	return (remalloc_result_of_glob(str, pre_result, n, begin));
}

void	processing_stars(char **str)
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

char	**expand_v(char *str)
{
	char	*res;
	char	*buf;
	int		fuck_norm[3];
	int		i;
	int		j;

	processing_stars(&str);
	res = xmalloc(sizeof(char) * (ft_strlen(str) + 1));
	frashing_values(fuck_norm, &i, &j);
	while (str[i])
	{
		if ((str[i] == '$' || tilda_case_check(str, i)) && !fuck_norm[1])
		{
			buf = get_pahom(&str[i], &i, &fuck_norm[0]);
			if (!buf)
				return (NULL);
			res = remalloc_result_of_extention(str, res, buf, fuck_norm[0]);
			j += ft_strlen(buf);
			free(buf);
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

char	*expand(char *str)
{
	char	*res;
	char	*buf;
	int		fuck_norm[3];
	int		i;
	int		j;

	processing_stars(&str);
	res = xmalloc(sizeof(char) * (ft_strlen(str) + 1));
	frashing_values(fuck_norm, &i, &j);
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
		else if ((str[i] == '$' || tilda_case_check(str, i)) && !fuck_norm[1])
		{
			buf = get_pahom(&str[i], &i, &fuck_norm[0]);
			if (!buf)
				return (NULL);
			res = remalloc_result_of_extention(str, res, buf, fuck_norm[0]);
			j += ft_strlen(buf);
			free(buf);
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
