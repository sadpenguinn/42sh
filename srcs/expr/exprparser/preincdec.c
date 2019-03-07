/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preincdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:54:09 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/21 18:03:24 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**            ++
**           /
**         ++
**        /
**	   VAR
**    /
**	..
*/

#include "expr.h"

t_astree	*preincdec(void)
{
	t_astree	*root;
	t_type		type;

	if (g_excurtok >= ((size_t *)g_extokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok))->type;
	if (type != EX_INC && type != EX_DEC)
		return (postincdec());
	g_excurtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = type;
	if (!(root->left = preincdec()))
		return (parseerror(root));
	return (root);
}
