/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:41:00 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 15:43:29 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**            /
**    PIPELINE
**   /
**...
*/

/*
**                     /
**              AND_OR2
**             /       \
**    PIPELEINE        AND_OR2_REST(type:'&&')
**   /                /           \
**...        PIPELEINE             AND_OR2_REST
*/

#include "parser.h"

t_astree	*and_or2(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = pipeline()))
		return (0);
	if (!(res[1] = and_or2_rest()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	/* XXX - Need norm type */
	root->type = 0;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
