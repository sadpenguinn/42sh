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
**    (root1)EX_EXPR
**          /    \
** (root0)EX_VAR    x=(root2)
**              / \
**   (expr2)EX_EXPR   NULL
*/

#include "expr.h"

t_astree	*expr2_1(void)
{
	t_astree	*root[3];

	if (!(root[0] = ft_memalloc(sizeof(t_astree))) ||
		!(root[1] = ft_memalloc(sizeof(t_astree))) ||
		!(root[2] = ft_memalloc(sizeof(t_astree))))
		return (0);
	root[0]->type = EX_VAR;
	root[0]->content =
		ft_strdup(((t_lexem *)vector_get_elem(g_extokens, g_excurtok++))->word);
	root[1]->type = EX_EXPR;
	root[1]->left = root[0];
	root[1]->right = root[2];
	root[2]->type = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok++))->type;
	if (!(root[2]->left = expr2()))
		return (0);
	return (root[1]);
}

t_astree	*expr2(void)
{
	int		type;

	if (g_excurtok >= ((size_t *)g_extokens)[2])
		return (0);
	if (((type = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok))->type) != EX_VAR)
		|| g_excurtok + 1 >= ((size_t *)g_extokens)[2])
		return (expr3());
	type = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok + 1))->type;
	if (type == EX_ASSIGN || type == EX_ADDASN || type == EX_SUBASN ||
		type == EX_MULASN || type == EX_DIVASN || type == EX_MODASN ||
		type == EX_LSHASN || type == EX_RSHASN || type == EX_ANDASN ||
		type == EX_XORASN || type == EX_ORASN)
		return (expr2_1());
	return (expr3());
}
