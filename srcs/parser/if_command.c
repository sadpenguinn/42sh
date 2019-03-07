/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:53:52 by bwerewol          #+#    #+#             */
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
**  CPLST    ELSE
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

t_astree		*if_command(void)
{
	t_astree	*res;
	t_astree	*root;

	if (!checktype(IF))
		return (0);
	if (!(res = compound_list()))
		return (parseerror(0));
	if (!checktype(THEN))
		return (parseerror(res));
	root = xmalloc(sizeof(t_astree));
	root->type = IF;
	root->left = res;
	if (!(root->right = compound_list()))
		return (parseerror(root));
	if (checktype(ELSE))
		if (!(root->right = get_else(root->right)))
			return (parseerror(root));
	if (checktype(ELIF))
		if (!(root->right = get_elif(root->right)))
			return (parseerror(root));
	if (!checktype(FI))
		return (parseerror(root));
	return (root);
}
