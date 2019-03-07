/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:42:59 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 19:44:02 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	      EX_EXPR
**	     /       \
**	EXPR9         EX_LOR
**	             /      \
**	        EXPR9       EX_LOR
*/

#include "expr.h"

static t_astree	*expr8_rest(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!checktype(EX_BAND))
		return (0);
	if (!(res = expr9()))
		return (parseerror(0));
	root = xmalloc(sizeof(t_astree));
	root->type = EX_BAND;
	root->left = res;
	root->right = expr8_rest();
	return (root);
}

t_astree		*expr8(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = expr9()))
		return (0);
	if (!(res[1] = expr8_rest()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = EX_EXPR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
