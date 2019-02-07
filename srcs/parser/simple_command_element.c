/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:49:39 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/07 21:10:05 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SCE - Simple Command Element
**
**     SCE(word) of REDIRECTION
*/

#include "parser.h"

t_astree	*cmd_name(void)
{
	t_astree	*res;
	t_astree	*root;

	if ((res = redirection()))
		return (res);
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = WORD;
	root->content = ft_strdup(
					((t_lexem *)vector_get_elem(g_tokens, g_curtok))->word);
	/* XXX - check assigment */
	if (1)
		root->type = ASSIGMENT_WORD;
	else
		root->type = WORD;
	g_curtok++;
	return (root);
}
