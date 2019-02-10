/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_rest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:35:31 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 15:44:23 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**            AND_OR
**           /      \
**        ...        AND_OR_REST(type:'||')
**                  /            \
**...        AND_OR2              AND_OR_REST
*/

#include "parser.h"

t_astree	*and_or_rest(void)
{
	t_astree	*res;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != OR_IF)
		return (0);
	g_curtok++;
	linebreak();
	if (!(res = and_or2()))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = OR_IF;
	root->left = res;
	root->right = and_or_rest();
	return (root);
}
