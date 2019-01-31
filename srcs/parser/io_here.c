/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_here.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:51:42 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 17:29:08 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*io_here(void)
{
	int			type;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != DLESS && type != DLESSDASH)
		return (0);
	g_curtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = type;
	if ((root->right = here_end()))
		return (root);
	free(root);
	return (0);
}
