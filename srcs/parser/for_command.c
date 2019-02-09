/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:51:53 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/09 19:02:07 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	CMPLST - CoMPound LiST
**	WLST - Word LiST
**
**           FOR
**          /   \
**      WORD     CMPLST
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
	int			type;
	t_lexem		*token;
	t_astree	*root;

	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	type = token->type;
	if (type != WORD && type != IF && type != THEN && type != ELSE &&
		type != ELIF && type != FI && type != FOR && type != WHILE &&
		type != UNTIL && type != DO && type != DONE && type != CASE &&
		type != IN && type != ESAC && type != FUNCTION && type != SELECT)
		return (0);
	if (!check_for_word(token->word))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = WORD;
	root->content = ft_strdup(token->word);
	g_curtok++;
	return (root);
}

static t_astree	*get_wordlist(t_astree	*root)
{
	t_astree	*temp;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != IN)
		return (0);
	g_curtok++;
	temp = root->left;
	root->left = xmalloc(sizeof(t_astree));
	root->left->type = IN;
	root->left->left = temp;
	root->left->right = word_list();
	if (!list_terminator())
		return (freeastree(root), parseerror());
	newline_list();
	return (root);
}

static t_astree	*get_compound_list()
{
	int			type;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != DO && type != OBRACE)
		return (0);
	g_curtok++;
	root = compound_list();
	if (type == DO)
		if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != DONE)
			return (freeastree(root), parseerror());
	if (type == OBRACE)
		if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != CBRACE)
			return (freeastree(root), parseerror());
	g_curtok++;
	return (root);
}

t_astree	*for_command(void)
{
	int			type;
	t_astree	*root;

	if (g_curtok + 2 >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != FOR)
		return (0);
	g_curtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = FOR;
	if (!(root->left = get_word()))
		return (freeastree(root), parseerror());
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == SEMI)
		g_curtok++;
	newline_list();
	if (type != SEMI)
		get_wordlist(root);
	if (!(root->right = get_compound_list()))
		return (freeastree(root), parseerror());
	return (root);
}
