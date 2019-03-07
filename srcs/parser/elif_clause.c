/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elif_clause.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:22:04 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
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
*/

#include "parser.h"

static t_astree	*get_else(t_astree *res)
{
	t_astree	*root;

	root = xmalloc(sizeof(t_astree));
	root->type = ELSE;
	root->left = res;
	if (!(root->right = compound_list()))
		return (freeastree(root));
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
	t_astree	*res;
	t_astree	*root;

	if (!(res = compound_list()))
		return (parseerror(0));
	if (!checktype(THEN))
		return (freeastree(res));
	root = xmalloc(sizeof(t_astree));
	root->type = IF;
	root->left = res;
	if (!(root->right = compound_list()))
		return (parseerror(root));
	if (checktype(ELSE))
		root->right = get_else(root->right);
	if (checktype(ELIF))
		if (!(root->right = get_elif(root->right)))
			return (parseerror(root));
	return (root);
}
