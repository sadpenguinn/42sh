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

#include "expr.h"

t_astree	*pre_unary_1(uint64_t type)
{
	t_astree	*root;

	g_curtok++;
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = (type == PLUS) ? EX_UPLUS : EX_UMINUS;
	/* XXX - PLUS maybe other def? */
	if (!(root->left = pre_unary()))
	{
		free(root);
		return (0);
	}
	return (root);
}

t_astree	*pre_unary_2(uint64_t type)
{
	t_astree	*root;

	g_curtok++;
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = (type == NOT) ? EX_LNOT : EX_BNOT;
	/* XXX - NOT maybe other def? */
	if (!(root->left = pre_unary()))
	{
		free(root);
		return (0);
	}
	return (root);
}

t_astree	*pre_unary(void)
{
	t_astree	*root;
	uint64_t	type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == PLUS || type == MINUS)
		return (pre_unary_1(type));
	if (type == NOT || type == EX_BNOT)
		return (pre_unary_2(type));
	if ((root = preincdec()))
		return (root);
	if ((root = operand()))
		return (root);
	return (0);
}
