/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 17:52:34 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 20:12:06 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**     (root0)EX_EXPR
**           /    \
** (cond)EX_EXPR      ?:(root1)
**                /  \
**     (expr3)EX_EXPR    EX_EXPR(expr3)
*/

#include "expr.h"

t_astree	*expr3(void)
{
	t_astree	*root[2];
	t_astree	*res[3];

	if (!(res[0] = expr4()))
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != EX_QUES)
		return (res[0]);
	g_curtok++;
	if (!(res[1] = expr3()))
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok++))->type != EX_COL)
		return (0);
	if (!(res[2] = expr3()))
		return (0);
	if (!(root[0] = ft_memalloc(sizeof(t_astree))) ||
		!(root[1] = ft_memalloc(sizeof(t_astree))))
		return (0);
	root[0]->left = res[0];
	root[0]->type = EX_EXPR;
	root[0]->right = root[1];
	root[1]->left = res[1];
	root[1]->type = EX_COND;
	root[1]->right = res[2];
	return (root[0]);
}
