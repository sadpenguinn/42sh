/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr9_rest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:45:51 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 19:47:31 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr9_rest_1(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr10()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EX_EQ;
	root->left = res;
	root->right = expr9_rest();
	return (root);
}

t_astree	*expr9_rest_2(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr10()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EX_NEQ;
	root->left = res;
	root->right = expr9_rest();
	return (root);
}

t_astree	*expr9_rest(void)
{
	uint64_t	type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == EX_EQ && ++g_curtok)
		return (expr9_rest_1());
	else if (type == EX_NEQ && ++g_curtok)
		return (expr9_rest_2());
	return (0);
}
