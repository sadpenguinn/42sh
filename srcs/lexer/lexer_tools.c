/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 12:10:37 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 22:32:00 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "lexer.h"

char	*push_symbol(t_string *string, char *str, size_t len)
{
	char	*symbol;

	if (!(symbol = string_push(string, str, len)))
		die();
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
