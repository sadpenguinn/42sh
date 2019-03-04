/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr7_rest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:41:36 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 19:42:53 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr7_rest_1(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr8()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EX_XOR;
	root->left = res;
	root->right = expr7_rest();
	return (root);
}

t_astree	*expr7_rest(void)
{
	uint64_t	type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == EX_XOR && ++g_curtok)
		return (expr7_rest_1());
	return (0);
}
