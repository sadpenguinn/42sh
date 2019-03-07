/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_list3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:08:06 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
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
**          /     \
**      PLST       AND_IF
**                /     \
**            PLST       ...
*/

#include "parser.h"

static t_astree	*simple_list3_rest(void)
{
	unsigned int	curtmp;
	t_astree		*root;

	curtmp = g_curtok;
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != AND_IF)
		return (0);
	g_curtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = AND_IF;
	if (!(root->left = simple_list3()))
		return (savecur(curtmp, root));
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (root);
	root->right = simple_list3_rest();
	return (root);
}

t_astree		*simple_list3(void)
{
	t_astree		*root;
	t_astree		*res[2];

	if (!(res[0] = pipeline_command()))
		return (0);
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (res[0]);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != AND_IF)
		return (res[0]);
	if (!(res[1] = simple_list3_rest()))
		return (parseerror(res[0]));
	root = xmalloc(sizeof(t_astree));
	root->type = LIST3;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
