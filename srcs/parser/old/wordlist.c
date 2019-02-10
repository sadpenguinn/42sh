/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:56:21 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/05 18:06:19 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**     \
**      WORD(content)
**          \
**           WORD(content)
**               \
**                WORD(content)
*/

#include "parser.h"

t_astree	*wordlist(void)
{
	t_lexem		*elem;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	elem = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (elem->type == SEMI || elem->type == NEWLINE)
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->content = ft_strdup(elem->word);
	root->right = wordlist();
	g_curtok++;
	return (root);
}
