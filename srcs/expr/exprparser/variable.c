/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:07:07 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/21 19:39:39 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

/*
**	EX_VAR
**        \
**         INDEX
*/

t_astree	*variable(void)
{
	t_astree	*root;
	t_lexem		*token;

	if (g_excurtok >= ((size_t *)g_extokens)[2])
		return (0);
	token = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok));
	if (token->type != EX_VAR)
		return (0);
	g_excurtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = EX_VAR;
	root->content = ft_strdup(token->word);
	if (!checktype(EX_OARRAY))
		return (root);
	if (!(root->right = expr()))
		return (parseerror(root));
	if (!checktype(EX_CARRAY))
		return (parseerror(root));
	return (root);
}
