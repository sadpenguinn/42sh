/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 12:10:37 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/20 20:24:40 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "lexer.h"

char	*push_symbol(char **string, char *str, size_t len)
{
	char	*symbol;

	symbol = *string;
	while (*str && len > 0)
	{
		**string = *str;
		(*string) += 1;
		str++;
		len--;
	}
	**string = '\0';
	(*string) += 1;
	return (symbol);
}

int		push_token(void **lexems, char *lexem, int state)
{
	t_lexem	new;

	if (state == TERM_SPACE - TERM_SHIFT)
		return (0);
	new.type = (t_type)(TERM_SHIFT + state);
	new.word = lexem;
	if (!(vector_push_back(lexems, (void *)(&new))))
		return (0);
	return (1);
}
