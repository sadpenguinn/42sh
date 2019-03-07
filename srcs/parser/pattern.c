/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:34:20 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	PAT - PATtern
**
** PAT
**    \
**     PAT
**        \
**         PAT
*/

#include "parser.h"

t_astree	*pattern(void)
{
	t_lexem			*token;
	t_astree		*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (!check_word_type(token->type))
		return (0);
	g_curtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = WORD;
	root->content = ft_strdup(token->word);
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (root);
	if (!checktype(PIPE))
		return (root);
	if (!(root->right = pattern()))
		return (parseerror(0));
	return (root);
}
