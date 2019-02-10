/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:12:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 16:06:07 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**        LIST
**       /    \
** AND_OR      LIST_REST(type:separator)
**            /    \
**      AND_OR      LIST_REST(type:separator)
**                 /    \
**                0      0
*/

#include "parser.h"

t_astree	*list(void)
{
	t_astree	*res;
	t_astree	*root;

	if (!(res = and_or()))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->left = res;
	/* XXX - Need norm type */
	root->type = 0;
	root->right = list_rest();
	return (root);
}
