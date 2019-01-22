/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr4_rest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:27:16 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 19:35:32 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr4_rest_1(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr5()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = LOR;
	root->left = res;
	root->right = expr4_rest();
	return (root);
}

t_astree	*expr4_rest(void)
{
	uint64_t	type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == LOR && ++g_curtok)
		return (expr4_rest_1());
	return (0);
}
