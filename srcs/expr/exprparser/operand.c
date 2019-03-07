/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 07:29:36 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/22 20:01:39 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	  OPERAND
*/

#include "expr.h"

static t_astree	*operand_bracket(void)
{
	t_astree	*res;

	if (!(checktype(EX_OBRACKET)))
		return (0);
	if (!(res = expr()))
		return (parseerror(0));
	if (!checktype(EX_CBRACKET))
		return (parseerror(res));
	return (res);
}

static t_astree	*operand_number(void)
{
	t_lexem		*token;
	t_astree	*root;

	if (g_excurtok >= ((size_t *)g_extokens)[2])
		return (0);
	token = ((t_lexem *)vector_get_elem(g_extokens, g_excurtok));
	if (token->type != EX_NUM)
		return (0);
	g_excurtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = EX_NUM;
	root->content = ft_strdup(token->word);
	return (root);
}

t_astree		*operand(void)
{
	t_astree	*res;

	if (!g_exprerr && (res = operand_bracket()))
		return (res);
	if (!g_exprerr && (res = operand_number()))
		return (res);
	if (!g_exprerr && (res = preincdec()))
		return (res);
	return (0);
}
