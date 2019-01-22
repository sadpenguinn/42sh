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

#include "expr.h"

t_astree	*preincdec_1(uint64_t type)
{
	t_astree	*root;

	g_curtok++;
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = (type == INC) ? PREINC : PREDEC;
	/* XXX - INC maybe other def? */
	if (!(root->left = postincdec()))
	{
		free(root);
		return (0);
	}
	return (root);
}

t_astree	*preincdec(void)
{
	t_astree	*root;
	uint64_t	type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == INC|| type == DEC)
		return (preincdec_1(type));
	if ((root = postincdec()))
		return (root);
	return (0);
}
