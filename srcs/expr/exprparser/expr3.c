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
**        (root0)EX_QUES(?)
**              /       \
** (cond)EX_EXPR        EX_COL(:)(root1)
**                     /  \
**       (expr3)EX_EXPR    EX_EXPR(expr3)
*/

#include "expr.h"

t_astree	*expr3(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!(res = expr4()))
		return (0);
	if (!checktype(EX_QUES))
		return (res);
	root = xmalloc(sizeof(t_astree));
	root->type = EX_QUES;
	root->left = res;
	root->right = xmalloc(sizeof(t_astree));
	root->right->type = EX_COL;
	if (!(root->right->left = expr3()))
		return (parseerror(root));
	if (!checktype(EX_COL))
		return (parseerror(root));
	if (!(root->right->right = expr3()))
		return (parseerror(root));
	return (root);
}
