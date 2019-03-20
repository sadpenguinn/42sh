/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithm_extention.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:58:20 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/19 16:51:16 by bbaelor-         ###   ########.fr       */
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
	if (g_exprerr)
	{
		write(1, "42sh: Division by zero\n", 23);
		return (NULL);
	}
	return (res);
}
