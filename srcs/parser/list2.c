/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:08:06 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/10 22:08:55 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	PLST - Pipeline LiST
**	N - Null
**
**      /
**  PLST
**
**      REST
**     /    \
** PLST      AND_IF
**          /      \
**      PLST        OR_IF
**                 /     \
**             PLST       ...
*/

#include "parser.h"

static t_astree	*list2_rest(void)
{
	int			type;
	t_astree	*root;

	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != AND_IF && type != OR_IF)
		return (0);
	g_curtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = type;
	if (!(root->left = pipeline_command()))
		return (freeastree(root));
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (root);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == AND_IF || type == OR_IF)
		if (!(root->right = list2_rest()))
			return (freeastree(root));
	return (root);
}

t_astree		*list2(void)
{
	int				type;
	t_astree		*root;
	t_astree		*res[2];

	if (!(res[0] = pipeline_command()))
		return (0);
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (res[0]);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != AND_IF && type != OR_IF)
		return (res[0]);
	if (!(res[1] = list2_rest()))
		return (freeastree(res[0]), parseerror());
	root = xmalloc(sizeof(t_astree));
	root->type = REST;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
