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
**    (root1)EXPR
**          /    \
** (root0)VAR    x=(root2)
**              / \
**   (expr2)EXPR   NULL
*/

#include "expr.h"

t_astree	*expr2_1(void)
{
	t_astree	*root[3];

	if (!(root[0] = ft_memalloc(sizeof(t_astree))) ||
		!(root[1] = ft_memalloc(sizeof(t_astree))) ||
		!(root[2] = ft_memalloc(sizeof(t_astree))))
		return (0);
	root[0]->type = VAR;
	root[0]->content =
		ft_strdup(((t_lexem *)vector_get_elem(g_tokens, g_curtok++))->word);
	root[1]->type = EXPR;
	root[1]->left = root[0];
	root[1]->right = root[2];
	root[2]->type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok++))->type;
	if (!(root[2]->left = expr2()))
		return (0);
	return (root[1]);
}

t_astree	*expr2(void)
{
	int		type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type) != VAR)
		|| g_curtok + 1 >= ((size_t *)g_tokens)[2])
		return (expr3());
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok + 1))->type;
	if (type == ASSIGN || type == ADDASGN || type == SUBASGN ||
		type == MULASGN || type == DIVASGN || type == MODASGN ||
		type == LSHASGN || type == RSHASGN || type == ANDASGN ||
		type == XORASGN || type == ORASGN)
		return (expr2_1());
	return (expr3());
}
