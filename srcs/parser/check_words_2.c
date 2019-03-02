/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_words_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:32:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/02 23:54:33 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			check_redir_num(char *str)
{
	return (ft_str_is_numeric(str));
}

int			check_func_name(char *str)
{
	if (ft_str_is_alpha(str))
		return (1);
	return (0);
}

int			check_for_word(char *str)
{
	if (ft_str_is_uppercase(str))
		return (1);
	return (0);
}

int			check_select_word(char *str)
{
	if (ft_str_is_uppercase(str))
		return (1);
	return (0);
}

/// 	* ->  arithmetic
///		((*;*;*))
int			check_arith_for(char *str)
{
	int		len;
	char	**words;
	char	*tmp;
	int		i;

	i = 0;
	if (str[0] != '(' || str[1] != '(')
		return (0);
	len = ft_strlen(str);
	if (str[len - 1] != ')' || str[len - 2] != ')')
		return (0);
	tmp = ft_strndup(&str[2], len - 4);
	words = ft_strsplit(tmp, ';');
	while (words[i])
	{
		if (!check_arith_word(words[i]))
			return (0);
		free(words[i]);
		i++;
		if (i > 3)
			return (0);
	}
	free(words);
	free(tmp);
	return (1);
}