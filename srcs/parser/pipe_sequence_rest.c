/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_sequence_rest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:47:58 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 18:58:04 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**                          /
**         PIPELINE_SEQUENCE(type:PIPE)
**        /                 \
** COMMAND                   PIPELINE_SEQUENCE_REST(type:PIPE)
**                          /                      \
**                   COMMAND                        PIPELINE_SEQUENCE_REST(type:PIPE)
*/

#include "parser.h"

t_astree	*pipeline_sequence_rest(void)
{
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != PIPE)
		return (0);
	g_curtok++;
	linebreak();
	root = xmalloc(sizeof(t_astree));
	root->type = PIPE;
	/* XXX - need free and err print */
	if (!(root->left = command()))
		return (0);
	root->right = pipeline_sequence_rest();
	return (root);
}
