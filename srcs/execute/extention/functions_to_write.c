/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_to_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:50:42 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/19 18:31:40 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"
#include "extention.h"

/*
** ${parameter:-word}	1	use_a_defalt_value
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
	printf("ENV: %s=%s\n", name, val);
}

char	*get_content_of_var(char *str)
{
	return (ft_strdup(str));

	// (void)str;
	// return (NULL);
}

char	*use_a_defalt_value(char *str)
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
	tmp = (ft_strndup(&str[i + 3], ft_strlen(&str[i + 3]) - 1));
	free (str);
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
	res = (ft_strndup(&str[i + 3], ft_strlen(&str[i + 3]) - 1));
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
	free (str);
	ft_putstr("42sh: ");
	ft_putstr(&tmp[2]);
	ft_putstr(": ");
	ft_putstr(res);
	ft_putstr("\n");
	exit(0);
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
	free (str);
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
	return (res);
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
	return (res);
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

char	*get_content_of_expression(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (ft_strstr(str, ":-"))
		return (use_a_defalt_value(str));
	if (ft_strstr(str, ":="))
		return (assign_a_default_value(str));
	if (ft_strstr(str, ":?"))
		return (display_error_if_null_or_unset(str));
	if (ft_strstr(str, ":+"))
		return (use_an_alternate_value(str));
	if (str[2] == '#')
		return (get_len_of_value(str));
	if (ft_strstr(str, "%%"))
		return (ft_strdup("<obosralsya(%%>"));
	if (ft_strstr(str, "%"))
		return (remove_smallest_suffix_pattern(str));
	if (ft_strstr(str, "##"))
		return (ft_strdup("<obosralsya(##>"));
	if (ft_strstr(str, "#"))
		return (remove_smallest_prefix_pattern(str));
	return ("something wrong in get_content_of_expression");
}
