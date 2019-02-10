/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_clause.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:01:49 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/09 20:17:05 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	CC - Case Clause
**	CCS - Case Clause Sequence
**	PATLST - PATtern LiST
**
**        CC
**       /  \
** PATLST    CCS
**          /   \
**    PATLST     CCS
**              /   \
**        PATLST     ...
**
**           CCS
**          /   \
**    PATLST     CCS
**              /   \
**        PATLST     ...
**
**        CC
**       /
** PATLST
*/

#include "parser.h"

t_astree	*case_clause(void)
{
	t_astree        *res[2];
	t_astree        *root;

	res[0] = case_clause_sequence();
	if (!(res[1] = pattern_list()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = SEMI;
	root->left = res[1];
	root->right = res[0];
	return (root);
}
