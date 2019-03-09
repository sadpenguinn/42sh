/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norma_fucking_sheet.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:33:03 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/01 20:34:50 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

void		iterator_for_expand(char *str, char *res, int *i, int *j)
{
	res[(*j)] = str[(*i)];
	(*j)++;
	(*i)++;
}

void		brackets_case_in_expand_v(const char *str, int *fuck_norm, int i)
{
	if (str[i] == '\'' && !fuck_norm[2])
		fuck_norm[1] = (fuck_norm[1] + 1) % 2;
	if (str[i] == '\"' && !fuck_norm[1])
		fuck_norm[2] = (fuck_norm[2] + 1) % 2;
}

int			brackets_case_in_expand(const char *str, int *f_n, int i)
{
	if (str[i] == '\'' && !f_n[2])
	{
		f_n[1] = (f_n[1] + 1) % 2;
		i++;
	}
	else if (str[i] == '\"' && !f_n[1])
	{
		f_n[2] = (f_n[2] + 1) % 2;
		i++;
	}
	return (i);
}

char		*pre_processing_in_expand(int *f_n, char **str, int *i, int *j)
{
	processing_stars(str);
	frashing_values(f_n, i, j);
	return (xmalloc(sizeof(char) * (ft_strlen(*str) + 1)));
}

int			fuck_you_fucking_norm(char *buf, int j)
{
	j += ft_strlen(buf);
	free(buf);
	return (j);
}
