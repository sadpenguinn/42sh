/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:04:10 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 20:06:10 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	      EX_EXPR
**	     /       \
**	EXPR13        EX_(operator)
**	             /      \
**	        EXPR13       EX_(operator)
*/

#include "expr.h"

static t_astree	*expr12_rest(void)
{
	t_type		type;
	t_astree	*root;
	t_astree	*res;

	if (g_excurtok >= ((size_t *)g_extokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok))->type;
	if (type != EX_ADD && type != EX_SUB)
		return (0);
	g_excurtok++;
	if (!(res = expr13()))
		return (parseerror(0));
	root = xmalloc(sizeof(t_astree));
	root->type = type;
	root->left = res;
	root->right = expr12_rest();
	return (root);
}

t_astree		*expr12(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = expr13()))
		return (0);
	if (!(res[1] = expr12_rest()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = EX_EXPR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
