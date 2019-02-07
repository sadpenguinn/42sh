/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:23:31 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/05 17:55:33 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**     \  /
**      IN(content)
*/

#include "parser.h"

t_astree	*in(void)
{
	t_lexem		*elem;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	elem = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (elem->type != IN)
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = IN;
	g_curtok++;
	return (root);
}
