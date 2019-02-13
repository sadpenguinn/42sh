/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 12:10:37 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/13 18:35:52 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "lexer.h"

char	*push_symbol(char **symbol_table, char *str, size_t len)
{
	char	*symbol;

	symbol = *symbol_table;
	while (*str && len > 0)
	{
		**symbol_table = *str;
		(*symbol_table) += 1;
		str++;
		len--;
	}
	**symbol_table = '\0';
	(*symbol_table) += 1;
	return (symbol);
}

int		push_token(void **lexems, char *lexem, int state)
{
	t_lexem	new;

	new.type = (t_type)(TERM_SHIFT + state);
	new.word = lexem;
	if (!(vector_push_back(lexems, (void *)(&new))))
		return (0);
	return (1);
}

