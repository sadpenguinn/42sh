/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:54:21 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/08 13:09:52 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*filename(void)
{
	t_lexem         *token;
	t_astree        *root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (parseerror());
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (token->type == NEWLINE || token->type == SEMI || token->type == AND)
		return (parseerror());
	root = xmalloc(sizeof(t_astree));
	root->content = ft_strdup(token->word);
	g_curtok++;
	return (root);
}
