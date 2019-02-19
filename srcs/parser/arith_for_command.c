/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arith_for_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:51:53 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 23:21:35 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	CMPLST - CoMPound LiST
**
**           FOR
**          /   \
**     ARITH     CMPLST
*/

#include "parser.h"

static t_astree	*get_word()
{
	t_lexem		*token;
	t_astree	*root;

	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (!check_word_type(token->type))
		return (0);
	if (!check_arith_for(token->word))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = WORD;
	root->content = ft_strdup(token->word);
	g_curtok++;
	if (list_terminator())
		newline_list();
	return (root);
}

static t_astree	*get_compound_list()
{
    t_type		type;
	t_astree	*res;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != DO && type != OBRACE)
		return (0);
	g_curtok++;
	/* root = xmalloc(sizeof(t_astree)); */
	/* root->type = DO; */
	if (!(res = compound_list()))
		return (0);
	if (type == DO)
		if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != DONE)
			return (freeastree(res));
	if (type == OBRACE)
		if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != CBRACE)
			return (freeastree(res));
	g_curtok++;
	return (res);
}

t_astree	*arith_for_command(void)
{
	t_astree	*root;

	if (g_curtok + 2 >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != FOR)
		return (0);
	g_curtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = FOR;
	if (!(root->left = get_word()))
		return (savecur(g_curtok - 1));
	if (!(root->right = get_compound_list()))
        return ((void)freeastree(root), parseerror());
	return (root);
}
