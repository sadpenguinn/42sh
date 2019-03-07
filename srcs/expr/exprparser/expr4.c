/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:40:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 19:26:41 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	      EX_EXPR
**	     /       \
**	EXPR5         EX_(operator)
**	             /      \
**	        EXPR5       EX_(operator)
*/

#include "expr.h"

static t_astree	*expr4_rest(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!checktype(EX_LOR))
		return (0);
	if (!(res = expr5()))
		return (parseerror(0));
	root = xmalloc(sizeof(t_astree));
	root->type = EX_LOR;
	root->left = res;
	root->right = expr4_rest();
	return (root);
}

t_astree		*expr4(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = expr5()))
		return (0);
	if (!(res[1] = expr4_rest()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = EX_EXPR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
