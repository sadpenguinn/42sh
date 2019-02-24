/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_to_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:50:42 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/24 19:00:21 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"
#include "extention.h"

/*
** ${parameter:-word}	1	use_a_default_value
** ${parameter:=word}	2	assign_a_default_value
** ${parameter:?word}	3	display_error_if_null_or_unset
** ${parameter:+word}	4	use_an_alternate_value
** ${#parameter}		5	get_len_of_value
** ${parameter%}		6	remove_smallest_suffix_pattern
** ${parameter%%}		7
** ${parameter#}		8	remove_smallest_prefix_pattern
** ${parameter##}		9
** $VAR					10	get_classic_var
** $(programm)			11	get_output_of_programm
*/

char	*get_last_n_symbols(char *str, int n, int freed)
{
	int		i;
	char	*res;

	i = ft_strlen(str) - n;
	res = ft_strdup(&str[i]);
	if (freed)
		free(str);
	return (res);
}

void	push_to_enviroment(char *name, char *val)
{
	ssetenv(name, val);
	printf("ENV: %s=%s\n", name, val);
}

char	*get_content_of_var(char *str)
{
	return (sgetenv(str));
}

char	*use_a_default_value(char *str)
{
	char	*tmp;
	int		i;
	char	*res;

	i = 0;
	while (str[i + 1] != ':')
		i++;
	tmp = ft_strndup(str, i + 1);
	res = get_content_of_var(&tmp[2]);
	free(tmp);
	if (res)
		return (res);
	tmp = ft_strndup(&str[i + 3], ft_strlen(&str[i + 3]) - 1);
	free(str);
	return (tmp);
}

char	*assign_a_default_value(char *str)
{
	char	*tmp;
	int		i;
	char	*res;

	i = 0;
	while (str[i + 1] != ':')
		i++;
	tmp = ft_strndup(str, i + 1);
	res = get_content_of_var(&tmp[2]);
	if (res)
	{
		free(tmp);
		return (res);
	}
	res = ft_strndup(&str[i + 3], ft_strlen(&str[i + 3]) - 1);
	push_to_enviroment(&tmp[2], res);
	free(str);
	return (res);
}

char	*display_error_if_null_or_unset(char *str)
{
	char	*tmp;
	int		i;
	char	*res;

	i = 0;
	while (str[i + 1] != ':')
		i++;
	tmp = ft_strndup(str, i + 1);
	res = get_content_of_var(&tmp[2]);
	free(tmp);
	if (res)
		return (res);
	res = (ft_strndup(&str[i + 3], ft_strlen(&str[i + 3]) - 1));
	free(str);
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putstr_fd(&tmp[2], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(res, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	free(res);
	return (NULL);
}

char	*use_an_alternate_value(char *str)
{
	char	*tmp;
	int		i;
	char	*res;

	i = 0;
	while (str[i + 1] != ':')
		i++;
	tmp = ft_strndup(str, i + 1);
	res = get_content_of_var(&tmp[2]);
	free(tmp);
	if (!res)
		return (ft_strdup(""));
	tmp = (ft_strndup(&str[i + 3], ft_strlen(&str[i + 3]) - 1));
	free(str);
	return (tmp);
}

char	*get_len_of_value(char *str)
{
	char	*tmp;
	char	*res;

	tmp = ft_strndup(str, ft_strlen(str) - 1);
	res = get_content_of_var(&tmp[3]);
	free(tmp);
	free(str);
	if (!res)
		return (ft_itoa(0));
	return (ft_itoa(ft_strlen(res)));
}

char	*remove_smallest_suffix_pattern(char *str)
{
	char	*tmp;
	char	*pattern;
	int		i;
	char	*res;
	char	*to_check;

	i = 0;
	while (str[i] != '%')
		i++;
	tmp = ft_strndup(str, i);
	res = get_content_of_var(&tmp[2]);
	if (!res)
		return (ft_strdup(""));
	pattern = ft_strndup(&str[i + 1], ft_strlen(&str[i + 3]) + 1);
	to_check = get_last_n_symbols(res, ft_strlen(pattern), 0);
	if (pattern && pattern[0] && !ft_strcmp(pattern, to_check))
		return (ft_strndup(res, ft_strlen(res) - ft_strlen(pattern)));
	return (ft_strdup(res));
}

char	*remove_smallest_prefix_pattern(char *str)
{
	char	*tmp;
	char	*pattern;
	int		i;
	char	*res;

	i = 0;
	while (str[i] != '#')
		i++;
	tmp = ft_strndup(str, i);
	res = get_content_of_var(&tmp[2]);
	if (!res)
		return (ft_strdup(""));
	pattern = ft_strndup(&str[i + 1], ft_strlen(&str[i + 3]) + 1);
	if (pattern && pattern[0] && !ft_strncmp(res, pattern, ft_strlen(pattern)))
		return (ft_strdup(&res[ft_strlen(pattern)]));
	return (ft_strdup(res));
}

char	*get_classic_var(char *str)
{
	char	*res;

	res = get_content_of_var(&str[1]);
	free(str);
	if (res)
		return (res);
	return (ft_strdup(""));
}

char	*get_output_of_programm(char *str)
{
	return (ft_strdup(str));
}

char	*erase_repetitions_recursion(char *str)
{
	char	*tmp;

	tmp = ft_strchr(&str[1], '$');
	if (!tmp)
		return (str);
	return (ft_strjoin("$", expand(&str[1]), 0));
}

char 	*classic_get_env(char *str)
{
	char *res;

	res = sgetenv(str);
	if (!res)
		return (ft_strdup(""));
	else
		return (ft_strdup(res));
}

char	*get_content_of_expression(char *str)
{
	char 	*res;

	str = erase_repetitions_recursion(str);
	if (str[1] != '(' && str[1] != '[' && str[1] != '{')
		res = (classic_get_env(&str[1]));
	else if (ft_strstr(str, ":-"))
		res = (use_a_default_value(str));
	else if (ft_strstr(str, ":="))
		res = (assign_a_default_value(str)); //
	else if (ft_strstr(str, ":?"))
		res = (display_error_if_null_or_unset(str));
	else if (ft_strstr(str, ":+"))
		res = (use_an_alternate_value(str));//
	else if (str[2] == '#')
		res = (get_len_of_value(str)); //
	else if (ft_strstr(str, "%%"))
		res = (ft_strdup("<obosralsya(%%>"));
	else if (ft_strstr(str, "%"))
		res = (remove_smallest_suffix_pattern(str)); //
	else if (ft_strstr(str, "##"))
		res = (ft_strdup("<obosralsya(##>"));
	else if (ft_strstr(str, "#"))
		res = (remove_smallest_prefix_pattern(str)); //
	else
		res = ft_strdup("something wrong in get_content_of_expression");
	free(str);
	return (res);
}
