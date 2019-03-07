/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:45:48 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 20:06:48 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	      EX_EXPR
**	     /       \
**	EXPR14        EX_(operator)
**	             /      \
**	        EXPR14       EX_(operator)
*/

#include "expr.h"

static t_astree	*expr13_rest(void)
{
	t_type		type;
	t_astree	*root;
	t_astree	*res;

	if (g_excurtok >= ((size_t *)g_extokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok))->type;
	if (type != EX_MUL && type != EX_DIV && type != EX_MOD)
		return (0);
	g_excurtok++;
	if (!(res = expr14()))
		return (parseerror(0));
	root = xmalloc(sizeof(t_astree));
	root->type = type;
	root->left = res;
	root->right = expr13_rest();
	return (root);
}

t_astree		*expr13(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = expr14()))
		return (0);
	if (!(res[1] = expr13_rest()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = EX_EXPR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
