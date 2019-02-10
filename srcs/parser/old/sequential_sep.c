/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequential_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:11:52 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/05 16:17:04 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
**     \              /
**      SEQUENTIAL_SEP(type:';' | '\n')
*/

#include "parser.h"

t_astree	*sequential_sep(void)
{
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type == NEWLINE)
		return (newline_list());
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != SEMI)
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = SEMI;
	g_curtok++;
	linebreak();
	return (root);
}
