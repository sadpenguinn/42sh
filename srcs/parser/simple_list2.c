/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:08:06 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/11 13:17:48 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	PLST - Pipeline LiST
**	N - Null
**
**      /
**  PLST
**
**      LIST2
**     /    \
** PLST      AND_IF
**          /      \
**      PLST        OR_IF
**                 /     \
**             PLST       ...
*/

#include "parser.h"

static t_astree	*simple_list2_rest(void)
{
	unsigned int	curtmp;
	t_type		type;
	t_astree	*root;

	curtmp = g_curtok;
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != AND_IF && type != OR_IF)
		return (0);
	g_curtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = type;
	if (!(root->left = pipeline_command()))
		return (savecur(curtmp), freeastree(root));
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (root);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == AND_IF || type == OR_IF)
		if (!(root->right = simple_list2_rest()))
			return (freeastree(root));
	return (root);
}

t_astree		*simple_list2(void)
{
	t_type			type;
	t_astree		*root;
	t_astree		*res[2];

	if (!(res[0] = pipeline_command()))
		return (0);
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (res[0]);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != AND_IF && type != OR_IF)
		return (res[0]);
	if (!(res[1] = simple_list2_rest()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = LIST2;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
