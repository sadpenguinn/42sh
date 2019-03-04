/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr10_rest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:48:35 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 20:01:31 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr10_rest_1(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr11()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = GT;
	root->left = res;
	root->right = expr10_rest();
	return (root);
}

t_astree	*expr10_rest_2(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr11()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = GEQ;
	root->left = res;
	root->right = expr10_rest();
	return (root);
}

t_astree	*expr10_rest_3(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr11()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = LT;
	root->left = res;
	root->right = expr10_rest();
	return (root);
}

t_astree	*expr10_rest_4(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr11()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = LEQ;
	root->left = res;
	root->right = expr10_rest();
	return (root);
}

t_astree	*expr10_rest(void)
{
	uint64_t	type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == GT && ++g_curtok)
		return (expr10_rest_1());
	else if (type == GEQ && ++g_curtok)
		return (expr10_rest_2());
	else if (type == LT && ++g_curtok)
		return (expr10_rest_3());
	else if (type == LEQ && ++g_curtok)
		return (expr10_rest_4());
	return (0);
}
