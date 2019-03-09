/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr14.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:50:55 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 20:08:10 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	      EX_EXPR
**	     /       \
**	EXPR15        EX_(operator)
**	             /      \
**	        EXPR15       EX_(operator)
*/

#include "expr.h"

static t_astree	*expr14_rest(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!checktype(EX_POW))
		return (0);
	if (!(res = preunary()))
		return (parseerror(0));
	root = xmalloc(sizeof(t_astree));
	root->type = EX_POW;
	root->left = res;
	root->right = expr14_rest();
	return (root);
}

t_astree		*expr14(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = preunary()))
		return (0);
	if (!(res[1] = expr14_rest()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = EX_EXPR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
