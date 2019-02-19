/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:51:53 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 23:21:31 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	CMPLST - CoMPound LiST
**	WLST - Word LiST
**
**           FOR
**          /   \
**        IN     CMPLST
**       /
**   WORD
**
**           FOR
**          /   \
**        IN     CMPLST
**       /  \
**   WORD    WLST
*/

#include "parser.h"

static t_astree	*get_word()
{
	t_lexem		*token;
	t_astree	*root;

	if (g_curtok + 1 >= ((size_t *)g_tokens)[2])
		return (0);
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (!check_word_type(token->type))
		return (0);
	if (!check_for_word(token->word))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = WORD;
	root->content = ft_strdup(token->word);
	g_curtok++;
	return (root);
}

static t_astree	*get_wordlist(t_astree	*left)
{
	if (!checktype(IN))
		return (left);
	left->right = word_list();
	if (!list_terminator())
		return (freeastree(left));
	newline_list();
	return (left);
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

t_astree	*for_command(void)
{
	int			type;
	t_astree	*root;

printf("in for_command\n");
	if (!checktype(FOR))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->left = xmalloc(sizeof(t_astree));
	root->type = FOR;
	root->left->type = IN;
	if (!(root->left->left = get_word()))
		return (freeastree(root), parseerror());
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == SEMI)
		g_curtok++;
	newline_list();
	if (type != SEMI)
		if (!(root->left = get_wordlist(root->left)))
			return (parseerror());
	if (!(root->right = get_compound_list()))
		return (freeastree(root), parseerror());
	return (root);
}
