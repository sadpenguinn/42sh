/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:23:42 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 16:06:56 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**			                    /
**                      PIPELINE(type:NOT)
**                     /
**    PIPELINE_SEQUENCE
*/

/*
**                     /
**    PIPELINE_SEQUENCE
**   /
** ...
*/

#include "parser.h"

t_astree	*pipeline(void)
{
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != BANG)
		return (pipeline_sequence());
	g_curtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = NOT;
	root->left = pipeline_sequence();
	return (root);
}
