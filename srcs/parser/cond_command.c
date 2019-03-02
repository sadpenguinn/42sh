/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cond_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:12:50 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*cond_command(void)
{
	t_lexem		*token;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return ((t_astree *)parseerror());
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (token->type != COND)
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = COND;
	root->content = ft_strdup(token->word);
	g_curtok++;
	return (root);
}
