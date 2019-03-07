/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:35:04 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 19:36:34 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	      EX_EXPR
**	     /       \
**	EXPR7         EX_LOR
**	             /      \
**	        EXPR7       EX_LOR
*/

#include "expr.h"

static t_astree	*expr6_rest(void)
{
	t_astree	*root;
	t_astree	*res;

	if (!checktype(EX_BOR))
		return (0);
	if (!(res = expr7()))
		return (parseerror(0));
	root = xmalloc(sizeof(t_astree));
	root->type = EX_BOR;
	root->left = res;
	root->right = expr6_rest();
	return (root);
}

t_astree		*expr6(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = expr7()))
		return (0);
	if (!(res[1] = expr6_rest()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = EX_EXPR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
