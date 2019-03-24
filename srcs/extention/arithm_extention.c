/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithm_extention.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:58:20 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/24 10:35:38 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

char	*get_arithm_extention(char *str)
{
	char	*expression_ex;
	char	*res;

	if (str[1] == '[')
		expression_ex = ft_strndup(&str[2], ft_strlen(&str[1]) - 2);
	else
		expression_ex = ft_strndup(&str[3], ft_strlen(&str[2]) - 3);
	res = expression(expression_ex);
	if (g_calcerr)
	{
		write(1, "42sh: Division by zero\n", 23);
		return (NULL);
	}
	return (res);
}
