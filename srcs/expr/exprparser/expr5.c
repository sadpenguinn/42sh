/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:31:07 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 19:31:53 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	      EX_EXPR
**	     /       \
**	EXPR6         EX_LOR
**	             /      \
**	        EXPR6       EX_LOR
*/

#include "expr.h"

static t_astree	*expr5_rest(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!exchecktype(EX_LAND))
		return (0);
	if (!(res = expr6()))
		return (exparseerror(0));
	root = xmalloc(sizeof(t_astree));
	root->type = EX_LAND;
	root->left = res;
	root->right = expr5_rest();
	return (root);
}

t_astree		*expr5(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = expr6()))
		return (0);
	if (!(res[1] = expr5_rest()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = EX_EXPR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
