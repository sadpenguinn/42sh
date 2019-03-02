/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:31:39 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	PL - PipeLine
**
**    /
**  PL
**
**    REST
**   /    \
** PL      PIPE
**        /    \
**      PL      BAR_AND
**             /       \
**           PL        ...
*/

#include "parser.h"

static t_astree	*pipeline_rest(void)
{
	int			type;
	t_astree	*root;

	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != PIPE)
		return (0);
	g_curtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = type;
	if (!(root->left = command()))
		return ((t_astree *)freeastree(root));
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (root);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == PIPE)
		if (!(root->right = pipeline_rest()))
			return ((t_astree *)freeastree(root));
	return (root);
}

t_astree		*pipeline(void)
{
	int				type;
	t_astree		*root;
	t_astree		*res[2];

	if (!(res[0] = command()))
		return (0);
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (res[0]);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != PIPE)
		return (res[0]);
	if (!(res[1] = pipeline_rest()))
		return ((t_astree *)(freeastree(res[0]) | parseerror()));
	root = xmalloc(sizeof(t_astree));
	root->type = REST;
	root->left = res[0];
	root->right = res[1];
	return (root);
}
