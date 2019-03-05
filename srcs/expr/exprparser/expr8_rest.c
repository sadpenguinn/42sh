/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr8_rest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:44:05 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 19:45:09 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr8_rest_1(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr9()))
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EX_BAND;
	root->left = res;
	root->right = expr8_rest();
	return (root);
}

t_astree	*expr8_rest(void)
{
	uint64_t	type;

	if (g_excurtok >= ((size_t *)g_extokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok))->type;
	if (type == EX_BAND && ++g_excurtok)
		return (expr8_rest_1());
	return (0);
}
