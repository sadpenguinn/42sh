/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:32:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/02 23:14:34 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_arith_word(char *str)
{
	int		len;
	int		i;

	i = 0;
	if (str[0] != '(' || str[1] != '(')
		return (0);
	len = ft_strlen(str);
	if (str[len - 1] != ')' || str[len - 2] != ')')
		return (0);
	return (1);
}

int	check_assigment_word(const char *str)
{
	int i;

	i = 0;
	if (!str || !str[0] || (str[0] <= '9' && str[0] >= '0') || str[0] == '=')
		return (0);
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' &&
			str[i] <= 'Z') || (str[i] == '_') ||
			(str[i] >= 'a' && str[i] <= 'z'))
		i++;
	if (str[i] == '=')
		return (1);
	return (0);
}

int check_varname(const char *str)
{
	int i;

	i = 0;
	if (!str || !str[0] || (str[0] <= '9' && str[0] >= '0') || str[0] == '=')
		return (0);
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' &&
			str[i] <= 'Z') || (str[i] == '_') ||
			(str[i] >= 'a' && str[i] <= 'z'))
		i++;
	if (!str[i])
		return (1);
	return (0);
}

int	check_word_type(t_type type)
{
	if (type == WORD || type == IF || type == THEN || type == ELSE ||
		type == ELIF || type == FI || type == FOR || type == WHILE ||
		type == UNTIL || type == DO || type == DONE || type == CASE ||
		type == IN || type == ESAC || type == FUNCTION || type == SELECT ||
		type == NOT)
		return (1);
	return (0);
}
