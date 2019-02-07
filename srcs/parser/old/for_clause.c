/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_clause.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:29:56 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/02 19:12:20 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**              /
**           FOR
**          /   \
**    ((;;))     DO_GROUP
*/

/*
**              /
**           FOR
**          /   \
**        IN     DO_GROUP
**       /  \
**   NAME    WORDLIST
*/

#include "parser.h"

t_astree	*for_clause_1(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = name()))
		return (0);
	linebreak();
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != IN)
		return (res[0]);
	g_curtok++;
	res[1] = wordlist();
	root = xmalloc(sizeof(t_astree));
	root->type = IN;
	root->left = res[0];
	root->right = res[1];
	return (root);
}

t_astree	*for_clause(void)
{
	t_astree	*root;
	t_astree	*sep;
	t_astree	*res[2];

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != FOR)
		return (0);
	g_curtok++;
	res[0] = for_clause_1();
	if (!(sep = sequential_sep()))
		if (res[0]->type == IN)
			return (0);
	/* XXX need free sep */
	res[1] = do_group();
	root = xmalloc(sizeof(t_astree));
	return (root);
}
