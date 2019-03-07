/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postincdec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:37:08 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/21 18:01:21 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	      VAR
**	     /
**	   --
**	  /
**	--
*/

#include "expr.h"

static t_astree	*postincdec_rest(void)
{
	t_type		type;
	t_astree	*root;

	if (g_excurtok >= ((size_t *)g_extokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok))->type;
	if (type != EX_INC && type != EX_DEC)
		return (0);
	g_excurtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = type;
	root->left = postincdec_rest();
	return (root);
}

t_astree		*postincdec(void)
{
	t_astree	*root;

	if (!(root = variable()))
		return (0);
	root->left = postincdec_rest();
	return (root);
}
