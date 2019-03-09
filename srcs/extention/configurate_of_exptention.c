/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configurate_of_exptention.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:38:01 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/09 20:00:06 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

char	*use_an_alternate_value(char *str)
{
	char	*tmp;
	int		i;
	char	*res;

	i = 0;
	while (str[i + 1] != ':')
		i++;
	tmp = ft_strndup(str, i + 1);
	res = (&tmp[2]);
	free(tmp);
	if (!res)
		return (ft_strdup(""));
	tmp = (ft_strndup(&str[i + 3], ft_strlen(&str[i + 3]) - 1));
	return (tmp);
}

char	*get_len_of_value(char *str)
{
	char	*tmp;
	char	*res;

	tmp = ft_strndup(str, ft_strlen(str) - 1);
	res = get_content_of_var(&tmp[3]);
	free(tmp);
	if (!res)
		return (ft_itoa(0));
	return (ft_itoa(ft_strlen(res)));
}

char	*get_ex_tilda(char *str)
{
	int				i;
	char			*tmp;
	struct passwd	*user;

	if (!str[1] || str[1] == ' ' || str[1] == '/')
		return (ft_strdup(sgetenv("HOME", ENV_ALL)));
	i = 1;
	while (str[i] && str[i] != '/' && str[i] != ' ')
		i++;
	tmp = ft_strndup(str, i);
	if (!(user = getpwnam(&tmp[1])))
		return (tmp);
	free(tmp);
	tmp = ft_strdup(user->pw_dir);
	return (tmp);
}

char	*get_content_of_expression_helper(char **str, char **res)
{
	if (ft_strstr(*str, "%%"))
		*res = ft_strdup("not_relized_yet");
	else if (ft_strstr(*str, "%"))
		*res = remove_smallest_suffix_pattern(*str);
	else if (ft_strstr(*str, "##"))
		*res = ft_strdup("not_relized_yet");
	else if (ft_strstr(*str, "#"))
		*res = remove_smallest_prefix_pattern(*str);
	else
		*res = ft_strdup("something wrong in get_content_of_expression");
	free(*str);
	return (*res);
}

char	*get_content_of_expression(char *str)
{
	char	*res;

	str = erase_repetitions_recursion(str);
	if (str[0] == '~')
		res = get_ex_tilda(str);
	else if (str[1] != '(' && str[1] != '[' && str[1] != '{')
		res = classic_get_env(&str[1]);
	else if (ft_strstr(str, ":-"))
		res = use_a_default_value(str);
	else if (ft_strstr(str, ":="))
		res = assign_a_default_value(str);
	else if (ft_strstr(str, ":?"))
		res = display_error_if_null_or_unset(str);
	else if (ft_strstr(str, ":+"))
		res = use_an_alternate_value(str);
	else if (str[2] == '#')
		res = get_len_of_value(str);
	else
		return (get_content_of_expression_helper(&str, &res));
	free(str);
	return (res);
}
