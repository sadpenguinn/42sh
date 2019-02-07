/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:25:42 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/02 19:18:26 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**     \            /
**      SEPARATOR_OP(type:'&' | ';')
*/

#include "parser.h"

t_astree	*separator_op(void)
{
	int			type;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != AND && type != SEMI)
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = type;
	g_curtok++;
	return (root);
}
