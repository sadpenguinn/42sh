/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:45:14 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 19:47:42 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	      EX_EXPR
**	     /       \
**	EXPR10        EX_(operator)
**	             /      \
**	        EXPR10       EX_LOR
*/

#include "expr.h"

static t_astree	*expr9_rest(void)
{
	t_type		type;
	t_astree	*root;
	t_astree	*res;

	if (g_excurtok >= ((size_t *)g_extokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok))->type;
	if (type != EX_EQ && type != EX_NEQ)
		return (0);
	g_excurtok++;
	if (!(res = expr10()))
		return (exparseerror(0));
	root = xmalloc(sizeof(t_astree));
	root->type = type;
	root->left = res;
	root->right = expr9_rest();
	return (root);
}

t_astree		*expr9(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = expr10()))
		return (0);
	if (!(res[1] = expr9_rest()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = EX_EXPR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
