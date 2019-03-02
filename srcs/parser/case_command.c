/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:11:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	CC - Case Clause
**	CCS - Case Clause Sequence
**	PATLST - PATtern LiST
**
**      CASE
**     /    \
** WORD      CC
*/

#include "parser.h"

static t_astree	*get_caseword(void)
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
	root->type = WORD;
	root->content = ft_strdup(token->word);
	newline_list();
	return (root);
}

t_astree		*case_command(void)
{
	t_astree	*res;
	t_astree	*root;

	if (!checktype(CASE))
		return ((t_astree *)parseerror());
	if (!(res = get_caseword()))
		return ((t_astree *)parseerror());
	root = xmalloc(sizeof(t_astree));
	root->type = CASE;
	root->left = res;
	if (!checktype(IN))
		return ((t_astree *)(freeastree(root) | parseerror()));
	root->right = case_clause();
	newline_list();
	if (!checktype(ESAC))
		return ((t_astree *)(freeastree(root) | parseerror()));
	return (root);
}
