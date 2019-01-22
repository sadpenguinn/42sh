/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:07:07 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/21 19:39:39 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

/*
**        VAR
**       /   \
**  INDEX     SUBS
*/

t_astree	*variable_1(void)
{
	t_astree	*leaf;

	g_curtok++;
	if (!(leaf = ft_memalloc(sizeof(t_astree))))
		return (0);
	leaf->type = ALLINDEX;
	return (leaf);
}

t_astree	*variable_2(void)
{
	t_astree	*root;

	if (!(root = expr()))
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != CARRAY)
		/*  XXX - Need free root */
		return (0);
	g_curtok++;
	return (root);
}

t_astree	*variable(void)
{
	t_astree	*root;
	t_astree	*res;

	res = substitution();
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != VAR)
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->right = res;
	root->type = VAR;
	root->content =
		ft_strdup(((t_lexem *)vector_get_elem(g_tokens, g_curtok++))->word);
	if (g_curtok + 2 >= ((size_t *)g_tokens)[2] ||
		((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != OARRAY)
		return (root);
	g_curtok++;
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type == MUL)
		root->left = variable_1();
	else
		root->left = variable_2();
	return (root);
}
