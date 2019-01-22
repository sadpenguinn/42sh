/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 07:44:20 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/22 19:45:35 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"
#include "execute.h"

unsigned int		g_curtok;
void				*g_tokens;

int main(void)
{
	t_astree	*root;
	t_lexem	lex;

	g_tokens = vector_create(sizeof(t_lexem));
	lex.type = NUM;
	lex.word = "5";
	vector_push_back(&g_tokens, &lex);

	lex.type = ADD;
	lex.word = "+";
	vector_push_back(&g_tokens, &lex);

	/* lex.type = OBRACKET; */
	/* lex.word = "("; */
	/* vector_push_back(&g_tokens, &lex); */

	lex.type = NUM;
	lex.word = "8";
	vector_push_back(&g_tokens, &lex);

	/* lex.type = COMMA; */
	/* lex.word = ","; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = NUM; */
	/* lex.word = "3"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = ADD; */
	/* lex.word = "+"; */
	/* vector_push_back(&g_tokens, &lex); */

	/* lex.type = NUM; */
	/* lex.word = "10"; */
	/* vector_push_back(&g_tokens, &lex); */

	printf("Tok count:%lu\n", ((size_t *)g_tokens)[2]);

	root = expr();
	print_astree(root);
//	intmax_t ret = execute(root);
//	printf("%jd\n", ret);
	return (0);
}
