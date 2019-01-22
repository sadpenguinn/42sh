/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr12_rest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:01:45 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 20:06:02 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr12_rest_1(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr13()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = ADD;
	root->left = res;
	root->right = expr12_rest();
	return (root);
}

t_astree	*expr12_rest_2(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr13()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = SUB;
	root->left = res;
	root->right = expr12_rest();
	return (root);
}

t_astree	*expr12_rest(void)
{
	uint64_t	type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == ADD && ++g_curtok)
		return (expr12_rest_1());
	else if (type == SUB && ++g_curtok)
		return (expr12_rest_2());
	return (0);
}
