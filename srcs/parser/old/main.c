/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:04:10 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/29 16:53:20 by bwerewol         ###   ########.fr       */
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

	lex.type = GREAT;
	lex.word = ">";
	vector_push_back(&g_tokens, &lex);

	lex.type = WORD;
	lex.word = "file";
	vector_push_back(&g_tokens, &lex);

	lex.type = WORD;
	lex.word = "command";
	vector_push_back(&g_tokens, &lex);

	lex.type = NUMBER;
	lex.word = "2";
	vector_push_back(&g_tokens, &lex);

	lex.type = GREAT;
	lex.word = ">";
	vector_push_back(&g_tokens, &lex);

	lex.type = WORD;
	lex.word = "file";
	vector_push_back(&g_tokens, &lex);

	lex.type = WORD;
	lex.word = "ARG";
	vector_push_back(&g_tokens, &lex);

	printf("Tok count:%lu\n", ((size_t *)g_tokens)[2]);

	root = simple_command();
	print_astree(root);
	return (0);
}
