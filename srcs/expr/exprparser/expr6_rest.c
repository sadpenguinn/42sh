/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr6_rest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:36:39 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 19:40:18 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr6_rest_1(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr7()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EX_BOR;
	root->left = res;
	root->right = expr6_rest();
	return (root);
}

t_astree	*expr6_rest(void)
{
	uint64_t	type;

	if (g_excurtok >= ((size_t *)g_extokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok))->type;
	if (type == EX_BOR && ++g_excurtok)
		return (expr6_rest_1());
	return (0);
}
