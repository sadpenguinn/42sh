/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_def.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:55:26 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
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
	if (!check_word_type(token->type) || !check_func_name(token->word))
		return (0);
	g_curtok++;
	if (!checktype(OBRACKET))
		return ((t_astree *)savecur(g_curtok - 1));
	if (!checktype(CBRACKET))
		return ((t_astree *)savecur(g_curtok - 2));
	root = xmalloc(sizeof(t_astree));
	root->type = FUNCTION;
	root->content = ft_strdup(token->word);
	if (!(root->right = function_body()))
		return ((t_astree *)(freeastree(root) | parseerror()));
	return (root);
}

static t_astree	*function_def_2(void)
{
	t_lexem		*token;
	t_astree	*root;

	g_curtok++;
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (!check_word_type(token->type) || !check_func_name(token->word))
		return ((t_astree *)savecur(g_curtok - 1));
	g_curtok++;
	if (!checktype(OBRACKET))
		return ((t_astree *)savecur(g_curtok - 2));
	if (!checktype(CBRACKET))
		return ((t_astree *)savecur(g_curtok - 3));
	root = xmalloc(sizeof(t_astree));
	root->type = FUNCTION;
	root->content = ft_strdup(token->word);
	if (!(root->right = function_body()))
		return ((t_astree *)(freeastree(root) | parseerror()));
	return (root);
}

static t_astree	*function_def_3(void)
{
	t_lexem		*token;
	t_astree	*root;

	g_curtok++;
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (!check_word_type(token->type) || !check_func_name(token->word))
		return ((t_astree *)savecur(g_curtok - 1));
	g_curtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = FUNCTION;
	root->content = ft_strdup(token->word);
	if (!(root->right = function_body()))
		return ((t_astree *)(freeastree(root) | parseerror()));
	return (root);
}

t_astree		*function_def(void)
{
	t_astree	*res;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != FUNCTION)
		return (function_def_1());
	if ((res = function_def_2()))
		return (res);
	if ((res = function_def_3()))
		return (res);
	return (0);
}
