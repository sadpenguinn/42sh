/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_def.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:55:26 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/10 12:32:10 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	FN - FunctioN
**	FNBD - FunctioN BoDy
**
** FN(content:WORD)
**   \
**    FNBD
*/

#include "parser.h"

static t_astree	*function_def_1(void)
{
	t_lexem		*token;
	t_astree	*root;

	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (!check_func_name(token->word))
		return (savecur(g_curtok));
	g_curtok++;
	if (g_curtok + 1 >= ((size_t *)g_tokens)[2])
		return (parseerror());
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != OBRACKET ||
		((t_lexem *)vector_get_elem(g_tokens, g_curtok + 1))->type != CBRACKET)
		return (savecur(g_curtok - 1));
	root = xmalloc(sizeof(t_astree));
	root->type = FUNCTION;
	root->content = token->word;
	if (!(root->right = function_body()))
		return (freeastree(root), parseerror());
	return (root);
}

static t_astree	*function_def_2(void)
{
	t_lexem		*token;
	t_astree	*root;

	g_curtok++;
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (!check_func_name(token->word))
		return (savecur(g_curtok - 1));
	g_curtok++;
	if (g_curtok + 1 >= ((size_t *)g_tokens)[2])
		return (parseerror());
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != OBRACKET ||
		((t_lexem *)vector_get_elem(g_tokens, g_curtok + 1))->type != CBRACKET)
		return (savecur(g_curtok - 2));
	root = xmalloc(sizeof(t_astree));
	root->type = FUNCTION;
	root->content = token->word;
	if (!(root->right = function_body()))
		return (freeastree(root), parseerror());
	return (root);
}

static t_astree	*function_def_3(void)
{
	t_lexem		*token;
	t_astree	*root;

	g_curtok++;
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (!check_func_name(token->word))
		return (savecur(g_curtok - 1));
	g_curtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = FUNCTION;
	root->content = token->word;
	if (!(root->right = function_body()))
		return (freeastree(root), parseerror());
	return (root);
}

t_astree	*function_def(void)
{
	t_astree	*res;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (parseerror());
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != FUNCTION)
		if ((res = function_def_1()))
			return (res);
	if ((res = function_def_2()))
		return (res);
	if ((res = function_def_3()))
		return (res);
	return (0);
}
