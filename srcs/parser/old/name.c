/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:00:31 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/05 17:23:26 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**     \    /
**      NAME(content)
*/

#include "parser.h"

t_astree	*name(void)
{
	t_lexem		*elem;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	elem = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	/* XXX check name */
	root = xmalloc(sizeof(t_astree));
	root->content = ft_strdup(elem->word);
	g_curtok++;
	return (root);
}
