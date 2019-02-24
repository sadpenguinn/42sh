/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_true_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:50:42 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/24 19:40:00 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
