/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:04:10 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 20:13:36 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

unsigned int	g_curtok;
void			*g_tokens;
int				g_parseerr = 0;

void			print_astree(t_astree *root);

int main(void)
{
	t_astree	*root;
	t_lexem	lex;

	g_tokens = vector_create(sizeof(t_lexem));

	lex.type = CASE;
	lex.word = "case";
	vector_push_back(&g_tokens, &lex);

	lex.type = WORD;
	lex.word = "A";
	vector_push_back(&g_tokens, &lex);

	lex.type = IN;
	lex.word = "in";
	vector_push_back(&g_tokens, &lex);

	lex.type = OBRACKET;
	lex.word = "(";
	vector_push_back(&g_tokens, &lex);

	lex.type = WORD;
	lex.word = "B";
	vector_push_back(&g_tokens, &lex);

	lex.type = CBRACKET;
	lex.word = ")";
	vector_push_back(&g_tokens, &lex);

	lex.type = WORD;
	lex.word = "ls";
	vector_push_back(&g_tokens, &lex);

	lex.type = DSEMI;
	lex.word = ";;";
	vector_push_back(&g_tokens, &lex);

	lex.type = OBRACKET;
	lex.word = "(";
	vector_push_back(&g_tokens, &lex);

	lex.type = WORD;
	lex.word = "D";
	vector_push_back(&g_tokens, &lex);

	lex.type = CBRACKET;
	lex.word = ")";
	vector_push_back(&g_tokens, &lex);

	lex.type = WORD;
	lex.word = "cat";
	vector_push_back(&g_tokens, &lex);

	lex.type = DSEMI;
	lex.word = ";;";
	vector_push_back(&g_tokens, &lex);

	lex.type = ESAC;
	lex.word = "esac";
	vector_push_back(&g_tokens, &lex);


	/* lex.type = IF; */
	/* lex.word = "if"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = IF; */
	/* lex.word = "if"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = WORD; */
	/* lex.word = "echo"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = SEMI; */
	/* lex.word = ";"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = THEN; */
	/* lex.word = "then"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = WORD; */
	/* lex.word = "echo"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = SEMI; */
	/* lex.word = ";"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = FI; */
	/* lex.word = "fi"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = LESS; */
	/* lex.word = "<"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = WORD; */
	/* lex.word = "a"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = SEMI; */
	/* lex.word = ";"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = THEN; */
	/* lex.word = "then"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = WORD; */
	/* lex.word = "echo"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = SEMI; */
	/* lex.word = ";"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = FI; */
	/* lex.word = "fi"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = LESS; */
	/* lex.word = "<"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = WORD; */
	/* lex.word = "a"; */
	/* vector_push_back(&g_tokens, &lex); */

	printf("Tok count:%lu\n", ((size_t *)g_tokens)[2]);
	g_parseerr = 0;
	root = inputunit();
	/* root = list1(); */
	/* root = for_command(); */
	/* root = pipeline_command(); */
	/* root = command(); */
	/* root = simple_command(); */
	printf("Result: %s\n", root ? "YES" : "NO");
	print_astree(root);
	freeastree(root);
	return (0);
}
