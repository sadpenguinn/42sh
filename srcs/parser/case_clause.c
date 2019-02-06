/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_clause.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:12:42 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/05 21:13:40 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**               /
**           CASE
**          /    \
**      WORD      CASE_LIST
*/

#include "parser.h"

t_astree	*case_clause_1(unsigned int curtmp)
{
	t_astree		*root;
	t_astree		*res;

	res = case_list_ns();
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (savecur(curtmp));
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != ESAC)
		return (savecur(curtmp));
	g_curtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = CASE;
	root->right = res;
	return (root);
}

t_astree	*case_clause(void)
{
	unsigned int	curtmp;
	t_astree		*res;

	curtmp = g_curtok;
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (savecur(curtmp));
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != CASE)
		return (savecur(curtmp));
	g_curtok++;
	linebreak();
	if (!(res = in()))
		return (savecur(curtmp));
	free(res);
	linebreak();
	return (case_clause_1(curtmp));
}
