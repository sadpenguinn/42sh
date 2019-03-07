/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:40:23 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 19:41:24 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	      EX_EXPR
**	     /       \
**	EXPR8         EX_LOR
**	             /      \
**	        EXPR8       EX_LOR
*/

#include "expr.h"

static t_astree	*expr7_rest(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!checktype(EX_XOR))
		return (0);
	if (!(res = expr8()))
		return (parseerror(0));
	root = xmalloc(sizeof(t_astree));
	root->type = EX_XOR;
	root->left = res;
	root->right = expr7_rest();
	return (root);
}

t_astree		*expr7(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = expr8()))
		return (0);
	if (!(res[1] = expr7_rest()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = EX_EXPR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
