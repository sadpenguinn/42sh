/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:43:33 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/02 17:02:03 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
**        COMPOUND_LIST
**       /             \
** AND_OR               COMPOUND_LIST_REST(type:sep)
**                     /                  \
**               AND_OR                    COMPOUND_LIST_REST(type:sep)
**                                        /
**                                       0
*/

#include "parser.h"

t_astree	*compound_list(void)
{
	t_astree	*res;
	t_astree	*root;

	linebreak();
	if (!(res = and_or()))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->left = res;
	/* XXX - Need norm type */
	root->type = 0;
	root->right = compound_list_rest();
	return (root);
}
