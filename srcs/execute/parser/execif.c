/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execif.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:19:31 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 22:07:27 by bwerewol         ###   ########.fr       */
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

#include "execute.h"

int		execif(t_astree *root, int fd[2], int flag)
{
	int			res;
	t_astree	*succes;
	t_astree	*failure;

	res = execlist1(root->left, fd, flag);
	succes = (root->right->type == ELSE) ? root->right->left : root->right;
	failure = (root->right) ? root->right->right : 0;
	if (res == EXIT_SUCCESS)
		return (execlist1(succes, fd, flag));
	if (!root->right)
		return (EXIT_SUCCESS);
	if (root->right->right->type == IF)
		return (execif(failure, fd, flag));
	else
		return (execlist1(failure, fd, flag));
}
