/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:02:32 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/23 11:23:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exprexecute.h"

/*
* Missing EX_COND, EX_QUES, EX_COL, all ASSIGNments
* g_sherror must be declared in 42sh.c
*/

int			g_sherror = 0;

intmax_t	exprexecute(t_astree *root)
{
	if (root->type == EX_NUM)
		return (ft_atoi(root->content));
	if (root->type == EX_VAR)
		return (get_var(root->content));
	if (root->type == EX_PREINC || root->type == EX_PREDEC ||
		root->type == EX_UPLUS || root->type EX_UMINUS ||
		root->type == EX_LNOT || root->type EX_BNOT)
		return (get_prefix(root));
	if (root->type == EX_EXPR)
		return (operators[root->right->type - OPSHIFT](execute(root->left), root->right));
	return (0);
}
