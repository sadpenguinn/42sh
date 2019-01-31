/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or2_rest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:16:41 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 15:43:40 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**            AND_OR
**           /      \
**        ...        AND_OR2_REST(type:'&&')
**                  /            \
**...        AND_OR2              AND_OR2_REST
*/

#include "parser.h"

t_astree	*and_or2_rest(void)
{
	t_astree	*res;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != AND_IF)
		return (0);
	g_curtok++;
	linebreak();
	if (!(res = pipeline()))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = OR_IF;
	root->left = res;
	root->right = and_or_rest();
	return (root);
}
