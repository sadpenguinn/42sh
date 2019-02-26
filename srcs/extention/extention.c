/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:30:34 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/26 19:31:01 by bbaelor-         ###   ########.fr       */
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

char	**expand_v(char *str)
{
	char	*res;
	char	*buf;
	int		fuck_norm[3];
	int		i;
	int		j;

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
