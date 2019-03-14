/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_unary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 11:54:15 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/21 18:03:05 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	      /
**	     ~
**	    /
**	   +
**	  /
**	OP
*/

#include "expr.h"

t_astree	*preunary(void)
{
	t_astree	*root;
	t_type		type;

	if (g_excurtok >= ((size_t *)g_extokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok))->type;
	if (type != EX_ADD && type != EX_SUB && type != EX_LNOT && type != EX_BNOT)
		return (operand());
	g_excurtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = type;
	if (!(root->left = preunary()))
		return (exparseerror(root));
	return (root);
}
