/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:32:08 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/02 17:15:21 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*newline_list(void)
{
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	root = xmalloc(sizeof(t_astree));
	g_curtok++;
	while (g_curtok <= ((size_t *)g_tokens)[2])
	{
		if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type == NEWLINE)
			g_curtok++;
		else
			break ;
	}
	return (root);
}
