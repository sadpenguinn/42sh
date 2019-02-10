/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:04:10 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/10 12:57:19 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

unsigned int	g_curtok;
void			*g_tokens;

void			print_astree(t_astree *root);

int main(void)
{
	t_astree	*root;
	t_lexem	lex;

	g_tokens = vector_create(sizeof(t_lexem));

	lex.type = IF;
	lex.word = "if";
	vector_push_back(&g_tokens, &lex);

	lex.type = THEN;
	lex.word = "then";
	vector_push_back(&g_tokens, &lex);

	lex.type = ELIF;
	lex.word = "else";
	vector_push_back(&g_tokens, &lex);

	lex.type = THEN;
	lex.word = "then";
	vector_push_back(&g_tokens, &lex);

	lex.type = ELSE;
	lex.word = "else";
	vector_push_back(&g_tokens, &lex);

	lex.type = FI;
	lex.word = "fi";
	vector_push_back(&g_tokens, &lex);

	/* lex.type = THEN; */
	/* lex.word = "case"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = ELSE; */
	/* lex.word = "in"; */
	/* vector_push_back(&g_tokens, &lex); */

	lex.type = NEWLINE;
	lex.word = "\n";
	vector_push_back(&g_tokens, &lex);

	printf("Tok count:%lu\n", ((size_t *)g_tokens)[2]);

	root = if_command();
	print_astree(root);
	return (0);
}
