/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr11_rest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 20:02:04 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 20:04:35 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr11_rest_1(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr12()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EX_LSH;
	root->left = res;
	root->right = expr11_rest();
	return (root);
}

t_astree	*expr11_rest_2(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr12()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EX_RSH;
	root->left = res;
	root->right = expr11_rest();
	return (root);
}

t_astree	*expr11_rest(void)
{
	uint64_t	type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == EX_LSH && ++g_curtok)
		return (expr11_rest_1());
	else if (type == EX_RSH && ++g_curtok)
		return (expr11_rest_2());
	return (0);
}
