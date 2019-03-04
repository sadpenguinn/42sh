/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr14_rest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:36:50 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 20:08:28 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr14_rest_1(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = operand()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = SUB;
	root->left = res;
	root->right = expr14_rest();
	return (root);
}

t_astree	*expr14_rest(void)
{
	uint64_t	type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == POWER && ++g_curtok)
		return (expr14_rest_1());
	return (0);
}
