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

unsigned int		g_excurtok;
void				*g_extokens;

int main(void)
{
	t_astree	*root;
	t_lexem		lex;

	g_extokens = vector_create(sizeof(t_lexem));
	lex.type = EX_NUM;
	lex.word = "8";
	vector_push_back(&g_extokens, &lex);

	lex.type = EX_ADD;
	lex.word = "**";
	vector_push_back(&g_extokens, &lex);

	/* lex.type = EX_OBRACKET; */
	/* lex.word = "("; */
	/* vector_push_back(&g_extokens, &lex); */

	lex.type = EX_NUM;
	lex.word = "2";
	vector_push_back(&g_extokens, &lex);

	lex.type = EX_ADD;
	lex.word = ",";
	vector_push_back(&g_extokens, &lex);

	lex.type = EX_NUM;
	lex.word = "3";
	vector_push_back(&g_extokens, &lex);

	/* lex.type = EX_ADD; */
	/* lex.word = "+"; */
	/* vector_push_back(&g_extokens, &lex); */

	/* lex.type = EX_NUM; */
	/* lex.word = "10"; */
	/* vector_push_back(&g_extokens, &lex); */

	printf("Tok count:%lu\n", ((size_t *)g_extokens)[2]);

	root = expr();
	print_astree(root);
	intmax_t ret = execute(root);
	printf("Return: %jd\n", ret);
	return (0);
}
