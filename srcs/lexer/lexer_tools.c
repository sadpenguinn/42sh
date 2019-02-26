/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 12:10:37 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 18:11:23 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "lexer.h"

static void		print_token(void *lexem)
{
	t_lexem		*lex;

	lex = lexem;
	ft_putstr(lex->word);
	ft_putstr(" -- ");
	ft_putnbrendl(lex->type - SHIFT);
}

void			lexer_free(t_lexer *lexer)
{
	free(lexer->lexems);
	free(lexer->symbol_table);
	free(lexer);
}

void			lexer_print(void *lexems)
{
	vector_foreach(lexems, print_token);
}

char			*push_symbol(char **string, char *str, size_t len)
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

int				push_token(void **lexems, char *lexem, int state)
{
	t_lexem	new;

	if (state == SPACE - SHIFT || state == TAB - SHIFT ||
									state == COMMENT - SHIFT)
		return (0);
	new.type = (t_type)(SHIFT + state);
	if (state == 72 || state == 79 || state == 83 || state == 101 ||
										state == 102 || state == 103)
		new.type = WORD;
	new.word = lexem;
	if (!(vector_push_back(lexems, (void *)(&new))))
		return (0);
	return (1);
}
