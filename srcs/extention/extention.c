/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:30:34 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/25 23:48:46 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

void		frashing_values(int *fuck_norm, int *i, int *j)
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

char		*free_and_null(char *str, char *res)
{
	if (str)
		free(str);
	if (res)
		free(res);
	return (NULL);
}

char		**expand_v(char *str)
{
	char	*res;
	char	*buf;
	int		fuck_norm[3];
	int		i;
	int		j;

	res = pre_processing_in_expand_v(fuck_norm, &str, &i, &j);
	while (str[i])
	{
		if (((str[i] == '$' || tilda_case_check(str, i)) && !fuck_norm[1])
				|| check_process_substitution_expand(&str[i]))
		{
			if (!(buf = get_pahom(&str[i], &i, &fuck_norm[0])))
				return ((char **)free_and_null(str, res));
			res = remalloc_result_of_extention(str, res, buf, fuck_norm[0]);
			j = fuck_you_fucking_norm(buf, j);
		}
		else
		{
			brackets_case_in_expand_v(str, fuck_norm, i);
			iterator_for_expand(str, res, &i, &j);
		}
	}
	free(str);
	return (strsplit_for_extention(res));
}

char		*expand(char *str)
{
	char	*res;
	char	*buf;
	int		f_n[3];
	int		i;
	int		j;

	res = pre_processing_in_expand(f_n, &str, &i, &j);
	while (str[i])
	{
		if ((str[i] == '\'' && !f_n[2]) || (str[i] == '\"' && !f_n[1]))
			i = brackets_case_in_expand(str, f_n, i);
		else if (((str[i] == '$' || tilda_case_check(str, i)) && !f_n[1])
						|| check_process_substitution_expand(&str[i]))
		{
			if (!(buf = get_pahom(&str[i], &i, &f_n[0])))
				return (free_and_null(str, res));
			res = remalloc_result_of_extention(str, res, buf, f_n[0]);
			j += ft_strlen(buf);
			free(buf);
		}
		else
			iterator_for_expand(str, res, &i, &j);
	}
	free(str);
	return (res);
}
