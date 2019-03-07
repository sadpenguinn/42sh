/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:19:53 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/21 11:53:52 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**      (root0)EX_EXPR
**            /       \
**	(res)PREID         x=(root1)
**                    / \
**      (expr2)EX_EXPR   NULL
*/

#include "expr.h"

static t_astree	*expr2_1(t_astree *res, t_type type)
{
	t_astree		*root[2];

	root[0] = xmalloc(sizeof(t_astree));
	root[1] = xmalloc(sizeof(t_astree));
	root[0]->type = EX_EXPR_ASN;
	root[0]->left = res;
	root[0]->right = root[1];
	root[1]->type = type;
	if (!(root[1]->left = expr2()))
		return (parseerror(root[0]));
	return (root[0]);
}

t_astree		*expr2(void)
{
	t_astree		*res;
	t_astree		*root;
	unsigned int	curtmp;
	int				type;

	curtmp = g_excurtok;
	if (!(res = preincdec()) || g_excurtok >= ((size_t *)g_extokens)[2])
	{
		savecur(curtmp, res);
		return (expr3());
	}
	type = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok))->type;
	if (type != EX_ASSIGN && type != EX_ADDASN && type != EX_SUBASN &&
		type != EX_MULASN && type != EX_DIVASN && type != EX_MODASN &&
		type != EX_LSHASN && type != EX_RSHASN && type != EX_ANDASN &&
		type != EX_XORASN && type != EX_ORASN)
	{
		savecur(curtmp, res);
		return (expr3());
	}
	if (!(root = expr2_1(res, type)))
		return (parseerror(res));
	return (root);
}
