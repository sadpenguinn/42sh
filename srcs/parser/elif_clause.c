/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elif_clause.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:22:04 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/09 21:22:47 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	CPLST - ComPound LiST
**
**        IF
**       /  \
**  CPLST    CPLST
**
**        IF
**       /  \
**  CPLST    ELSE
**          /    \
**     CPLST      CPLST
**
**        IF
**       /  \
**  CPLST    ELSE(elif)
**          /    \
**     CPLST      IF
**               /  \
**          CPLST    CPLST
**
*/

#include "parser.h"

t_astree	*get_else(t_astree *res)
{
	t_astree	*root;
	
}

t_astree	*elif_clause(void)
{
	t_astree        *res[2];
	t_astree        *root;

	if (!checktype(ELIF))
		return (0);
	if (!(res[0] = compound_list()))
		return (parseerror());
	if (!checktype(THEN))
		return (parseerror());
	if (!(res[1] = compound_list()))
		return (parseerror());
	root = xmalloc(sizeof(t_astree));
	root->type = ELIF;
	root->left = res[0];
	if (checktype(ELSE))
		root->right = get_else(res[1]);
	if (checktype(ELIF))
		root->right = get_elif(res[1]);
	return (root);




	curtmp = g_curtok;
	res = pattern_list();
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != DSEMI && type != SEMI_AND && type != DSEMI_AND)
		return (freeastree(res), savecur(curtmp));
	g_curtok++;
	root = xmalloc(sizeof(t_astree));
	root->type = DSEMI;
	root->left = res;
	root->right = case_clause_sequence();
	return (root);
}
