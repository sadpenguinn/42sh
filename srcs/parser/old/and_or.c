/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:28:09 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 15:40:43 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**           /
**    AND_OR2
**   /
**...
*/

/*
**                  /
**            AND_OR
**           /      \
**    AND_OR2        AND_OR_REST(type:'||')
**   /              /           \
**...        AND_OR2             AND_OR_REST
*/

#include "parser.h"

t_astree	*and_or(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = and_or2()))
		return (0);
	if (!(res[1] = and_or_rest()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	/* XXX - Need norm type */
	root->type = 0;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
