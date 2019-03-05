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

	g_excurtok++;
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = (type == EX_INC) ? EX_POSTINC : EX_POSTDEC;
	root->left = postincdec_rest();
	return (root);
}

t_astree	*postincdec_rest(void)
{
	uint64_t	type;

	if (g_excurtok >= ((size_t *)g_extokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok))->type;
	if (type == EX_INC || type == EX_DEC)
		return (postincdec_rest_1(type));
	return (0);
}
