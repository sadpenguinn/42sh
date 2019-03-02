/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:32:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/28 18:38:20 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		check_redir_num(char *str)
{
	return (ft_str_is_numeric(str));
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

int		check_select_word(char *str)
{
	if (ft_str_is_uppercase(str))
		return (1);
	return (0);
}

int		check_arith_for(char *str)
{
	if (ft_strchr(str, ';'))
		return (1);
	return (0);
}
