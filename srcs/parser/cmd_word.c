/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:52:14 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 15:45:10 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree        *cmd_word(void)
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
