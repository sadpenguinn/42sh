/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:04:10 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/09 20:16:51 by bwerewol         ###   ########.fr       */
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

	lex.type = CASE;
	lex.word = "case";
	vector_push_back(&g_tokens, &lex);

	lex.type = WORD;
	lex.word = "A";
	vector_push_back(&g_tokens, &lex);

	lex.type = IN;
	lex.word = "in";
	vector_push_back(&g_tokens, &lex);

	/* lex.type = OBRACKET; */
	/* lex.word = "("; */
	/* vector_push_back(&g_tokens, &lex); */

	lex.type = WORD;
	lex.word = "B";
	vector_push_back(&g_tokens, &lex);

	lex.type = CBRACKET;
	lex.word = ")";
	vector_push_back(&g_tokens, &lex);

	lex.type = DSEMI;
	lex.word = ";;";
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

	lex.type = DSEMI;
	lex.word = ";;";
	vector_push_back(&g_tokens, &lex);

	lex.type = ESAC;
	lex.word = "esac";
	vector_push_back(&g_tokens, &lex);


	lex.type = NEWLINE;
	lex.word = "\n";
	vector_push_back(&g_tokens, &lex);

	printf("Tok count:%lu\n", ((size_t *)g_tokens)[2]);

	root = case_command();
	print_astree(root);
	return (0);
}
