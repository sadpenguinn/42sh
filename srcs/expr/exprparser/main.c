/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 07:44:20 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/22 20:57:14 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"
#include "execute.h"


int main(void)
{
	t_astree	*root;
	t_lexem		lex;

	g_extokens = vector_create(sizeof(t_lexem));
	g_excurtok = 0;

	/* lex.type = EX_VAR; */
	/* lex.word = "3"; */
	/* vector_push_back(&g_extokens, &lex); */
	/* printf("%s->%d\n", lex.word, lex.type); */

	/* lex.type = EX_QUES; */
	/* lex.word = "?"; */
	/* vector_push_back(&g_extokens, &lex); */
	/* printf("%s->%d\n", lex.word, lex.type); */

	/* lex.type = EX_NUM; */
	/* lex.word = "7"; */
	/* vector_push_back(&g_extokens, &lex); */
	/* printf("%s->%d\n", lex.word, lex.type); */

	/* lex.type = EX_COL; */
	/* lex.word = ":"; */
	/* vector_push_back(&g_extokens, &lex); */
	/* printf("%s->%d\n", lex.word, lex.type); */

	/* lex.type = EX_NUM; */
	/* lex.word = "9"; */
	/* vector_push_back(&g_extokens, &lex); */
	/* printf("%s->%d\n", lex.word, lex.type); */



	lex.type = EX_VAR;
	lex.word = "V";
	vector_push_back(&g_extokens, &lex);
	printf("%s->%d\n", lex.word, lex.type);

	lex.type = EX_ASSIGN;
	lex.word = "=";
	vector_push_back(&g_extokens, &lex);
	printf("%s->%d\n", lex.word, lex.type);

	lex.type = EX_NUM;
	lex.word = "5";
	vector_push_back(&g_extokens, &lex);
	printf("%s->%d\n", lex.word, lex.type);

	printf("Tok count:%lu\n", ((size_t *)g_extokens)[2]);

	root = expr();
	print_astree(root);
	/* intmax_t ret = execute(root); */
	/* printf("Return: %jd\n", ret); */
	return (0);
}
