/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elif_clause.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:22:04 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/10 12:52:51 by bwerewol         ###   ########.fr       */
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

static t_astree	*get_else(t_astree *res)
{
	t_astree	*root;

	root = xmalloc(sizeof(t_astree));
	root->type = ELSE;
	root->left = res;
	root->right = compound_list();
	return (root);
}

static t_astree	*get_elif(t_astree *res)
{
	t_astree	*root;

	root = xmalloc(sizeof(t_astree));
	root->type = ELSE;
	root->left = res;
	if (!(root->right = elif_clause()))
		return (freeastree(root));
	return (root);
}

t_astree		*elif_clause(void)
{
	t_astree        *res;
	t_astree        *root;

	res = compound_list();
	if (!checktype(THEN))
		return (freeastree(res));
	root = xmalloc(sizeof(t_astree));
	root->type = IF;
	root->left = res;
	root->right = compound_list();
	if (checktype(ELSE))
		root->right = get_else(root->right);
	if (checktype(ELIF))
		if (!(root->right = get_elif(root->right)))
			return (freeastree(root), parseerror());
	return (root);
}
