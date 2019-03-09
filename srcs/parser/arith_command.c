/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arith_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 13:23:20 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*arith_command(void)
{
	t_lexem		*token;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (parseerror(0));
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (token->type != ARITH)
		return (0);
	if (!check_arith_word(token->word))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = ARITH;
	root->content = ft_strdup(token->word);
	g_curtok++;
	return (root);
}
