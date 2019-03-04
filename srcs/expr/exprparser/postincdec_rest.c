/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postincdec_rest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:52:59 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/21 18:01:54 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*postincdec_rest_1(uint64_t type)
{
	t_astree	*root;

	g_curtok++;
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = (type == INC) ? POSTINC : POSTDEC;
	root->left = postincdec_rest();
	return (root);
}

t_astree	*postincdec_rest(void)
{
	uint64_t	type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == INC || type == DEC)
		return (postincdec_rest_1(type));
	return (0);
}
