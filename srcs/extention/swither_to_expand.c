/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swither_to_expand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 00:10:23 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/26 00:10:52 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

char	*get_content_of_expression_helper(char **str, char **res)
{
	if (ft_strstr(*str, "%%"))
		*res = ft_strdup("not_relized_yet");
	else if ((*str)[0] == '<')
		*res = get_small_redir(*str);
	else if ((*str)[0] == '>')
		*res = get_grade_redir(*str);
	else if ((*str)[1] == '(')
		*res = get_output_of_programm(*str);
	else if (ft_strstr(*str, "%"))
		*res = remove_smallest_suffix_pattern(*str);
	else if (ft_strstr(*str, "##"))
		*res = ft_strdup("not_relized_yet");
	else if (ft_strstr(*str, "#"))
		*res = remove_smallest_prefix_pattern(*str);
	else
		*res = get_content_of_other_ex(*str);
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
	else if (str[1] == '[' || (str[1] == '(' && str[2] == '('))
		res = get_arithm_extention(str);
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
