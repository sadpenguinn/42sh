/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_clause_sequence.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:39:38 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/09 19:39:46 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	CCS - Case Clause Sequence
**	PATLST - PATtern LiST
**
**        CCS
**       /   \
** PATLST     CCS
**           /   \
**     PATLST     CCS
**               /   \
**         PATLST     ...
*/

#include "parser.h"

t_astree	*case_clause_sequence(void)
{
	int				type;
	unsigned int	curtmp;
	t_astree        *res;
	t_astree        *root;

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
