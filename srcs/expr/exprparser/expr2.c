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
**      (root0)EX_ASSIGN
**            /       \
**	(res)PREID         x(root1)
**                    / \
**      (expr2)EX_EXPR   NULL
*/

#include "expr.h"

static t_type	get_type(t_type type)
{
	if (type == EX_ASSIGN)
		return (EX_ASSIGN);
	if (type == EX_ADDASN || type == EX_SUBASN)
		return ((type == EX_ADDASN) ? EX_ADD : EX_SUB);
	if (type == EX_MULASN || type == EX_DIVASN)
		return ((type == EX_MULASN) ? EX_MUL : EX_DIV);
	if (type == EX_MODASN)
		return (EX_MOD);
	if (type == EX_LSHASN || type == EX_RSHASN)
		return ((type == EX_LSHASN) ? EX_LSH : EX_RSH);
	if (type == EX_ORASN || type == EX_ANDASN)
		return ((type == EX_ORASN) ? EX_BOR : EX_BAND);
	if (type == EX_XORASN)
		return (EX_XOR);
	return (-1);
}

static t_astree	*expr2_1(t_astree *res, t_type type)
{
	t_astree		*root[2];

	root[0] = xmalloc(sizeof(t_astree));
	root[1] = xmalloc(sizeof(t_astree));
	root[0]->type = EX_ASSIGN;
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
	if ((type = get_type(type)) == -1)
	{
		savecur(curtmp, res);
		return (expr3());
	}
	g_excurtok++;
	if (!(root = expr2_1(res, type)))
		return (parseerror(0));
	return (root);
}
