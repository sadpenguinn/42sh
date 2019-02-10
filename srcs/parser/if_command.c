/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:53:52 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/10 16:07:49 by bwerewol         ###   ########.fr       */
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
**
**        IF
**       /  \
**  CPLST    ELIF
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
	t_astree        *res;
	t_astree        *root;

	if (!checktype(IF))
		return (0);
	if (!(res = compound_list()))
		return (parseerror());
	if (!checktype(THEN))
		return (freeastree(res), parseerror());
	root = xmalloc(sizeof(t_astree));
	root->type = IF;
	root->left = res;
	if (!(root->right = compound_list()))
		return (freeastree(root), parseerror());
	if (checktype(ELSE))
		if (!(root->right = get_else(root->right)))
			return (freeastree(root), parseerror());
	if (checktype(ELIF))
		if (!(root->right = get_elif(root->right)))
			return (freeastree(root), parseerror());
	if (!checktype(FI))
		return (freeastree(root), parseerror());
	return (root);
}
