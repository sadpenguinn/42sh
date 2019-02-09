/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:32:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/09 14:59:50 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		check_redir_num(char *str)
{
	return (ft_str_is_numeric(str));
}

int		check_assigment_word(char *str)
{
	if (ft_strchr(str, '='))
		return (1);
	return (0);
}

int		check_func_name(char *str)
{
	if (ft_str_is_alpha(str))
		return (1);
	return (0);
}

int		check_for_word(char *str)
{
	if (ft_str_is_uppercase(str))
		return (1);
	return (0);
}

int		check_word_type(int type)
{
	if (type == WORD || type == IF || type == THEN || type == ELSE ||
		type == ELIF || type == FI || type == FOR || type == WHILE ||
		type == UNTIL || type == DO || type == DONE || type == CASE ||
		type == IN || type == ESAC || type == FUNCTION || type == SELECT)
		return (1);
	return (0);
}
