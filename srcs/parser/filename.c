/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:54:21 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*filename(void)
{
	t_lexem		*token;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (parseerror(0));
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (!check_word_type(token->type))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = WORD;
	root->content = ft_strdup(token->word);
	g_curtok++;
	return (root);
}
