/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:56:21 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/09 16:02:37 by bwerewol         ###   ########.fr       */
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

t_astree	*word_list(void)
{
	t_lexem		*token;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (!check_word_type(token->type))
		return (0);
	g_curtok++;
	root = xmalloc(sizeof(t_astree));
	root->content = ft_strdup(token->word);
	root->right = word_list();
	return (root);
}
