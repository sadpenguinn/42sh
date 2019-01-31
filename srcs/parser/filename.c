/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:54:21 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 15:45:35 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree        *filename(void)
{
	t_lexem         *token;
	t_astree        *root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	root = xmalloc(sizeof(t_astree));
	g_curtok++;
	root->type = WORD;
	root->content = ft_strdup(token->word);
	return (root);
}
