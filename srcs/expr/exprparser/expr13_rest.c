/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr13_rest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:01:45 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/22 20:55:17 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr13_rest_1(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr14()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EX_MUL;
	root->left = res;
	root->right = expr13_rest();
	return (root);
}

t_astree	*expr13_rest_2(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr14()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EX_DIV;
	root->left = res;
	root->right = expr13_rest();
	return (root);
}

t_astree	*expr13_rest_3(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr14()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EX_MOD;
	root->left = res;
	root->right = expr13_rest();
	return (root);
}

t_astree	*expr13_rest(void)
{
	uint64_t	type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == EX_MUL && ++g_curtok)
		return (expr13_rest_1());
	else if (type == EX_DIV && ++g_curtok)
		return (expr13_rest_2());
	else if (type == EX_MOD && ++g_curtok)
		return (expr13_rest_3());
	return (0);
}
