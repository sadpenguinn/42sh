/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:04:10 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/10 22:11:38 by bwerewol         ###   ########.fr       */
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

	lex.type = FOR;
	lex.word = "for";
	vector_push_back(&g_tokens, &lex);

	lex.type = WORD;
	lex.word = "(;;)";
	vector_push_back(&g_tokens, &lex);

	lex.type = DO;
	lex.word = "do";
	vector_push_back(&g_tokens, &lex);

	lex.type = DONE;
	lex.word = "done";
	vector_push_back(&g_tokens, &lex);

	lex.type = PIPE;
	lex.word = "|";
	vector_push_back(&g_tokens, &lex);

	lex.type = WORD;
	lex.word = "ls";
	vector_push_back(&g_tokens, &lex);

	lex.type = OR_IF;
	lex.word = "&&";
	vector_push_back(&g_tokens, &lex);

	lex.type = WORD;
	lex.word = "ls";
	vector_push_back(&g_tokens, &lex);

	/* lex.type = SEMI; */
	/* lex.word = ";"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = NEWLINE; */
	/* lex.word = "\n"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = NEWLINE; */
	/* lex.word = "\n"; */
	/* vector_push_back(&g_tokens, &lex); */

	printf("Tok count:%lu\n", ((size_t *)g_tokens)[2]);

	root = list2();
	/* root = pipeline_command(); */
	/* root = command(); */
	/* root = simple_command(); */
	print_astree(root);
	return (0);
}
