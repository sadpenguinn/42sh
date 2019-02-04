/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 12:10:37 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/02 19:20:11 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		push_token(void **lexems, char *lexem)
{
	t_lexem	new;

	new.type = TERM_WORD;
	new.word = lexem;
	if (!(vector_push_back(lexems, (void *)(&new))))
		return (0);
	return (1);
}

int		is_delim(char c)
{
	return (c == ' ' || c == '\t' || c =='\n');
}

/* char	*strsstr(const char *s1, const char *s2) */
/* { */
/* 	while (*s1 && *s2 && *s1 == *s2) */
/* 	{ */
/* 		s1++; */
/* 		s2++; */
/* 	} */
/* 	if (!*s2) */
/* 		return (((char *)s1) + 1); */
/* 	return (NULL); */
/* } */

/* int		get_type(char *lexem) */
/* { */
/* 	int	i; */

/* 	i = 0; */
/* 	while (g_terminals[i]) */
/* 	{ */
/* 		if (!ft_strcmp(g_terminals[i], lexem)) */
/* 			return (i); */
/* 		i++; */
/* 	} */
/* 	return (0); */
/* } */

void	*lexer_die(void *a1, void *a2, void *a3)
{
	if (a1)
		free(a1);
	if (a2)
		free(a2);
	if (a3)
		free(a3);
	return (NULL);
}

void	print_token(void *lexem)
{
	t_lexem		*lex;

	lex = (void *)lexem;
	ft_putendl(lex->word);
}
