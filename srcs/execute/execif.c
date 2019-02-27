/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execif.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:19:31 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:45:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	CPLST - ComPound LiST
**
**       IF
**      /  \
**  CMPD    IF_TRUE
**
**       IF
**      /  \
**  CMPD    ELSE
**         /    \
**  IF_TRUE      IF_FALSE
**
**       IF
**      /  \
**  CMPD    ELSE
**         /    \(if_false)
**  IF_TRUE      IF
**              /  \
**          CMPD    ...
*/

#include "execute.h"

int		execif(t_astree *root, int fd[2], int job, int isfork)
{
	int			res;
	t_astree	*if_true;
	t_astree	*failure;

	res = execlist1(root->left, fd, job, isfork);
	if (!root->right)
		return (EXIT_SUCCESS);
	if_true = (root->right->type == ELSE) ? root->right->left : root->right;
	failure = (root->right->type == ELSE) ? root->right->right : 0;
	if (res == EXIT_SUCCESS)
		return (execlist1(if_true, fd, job, isfork));
	if (root->right->type == ELSE && root->right->right->type == IF)
		return (execif(failure, fd, job, isfork));
	if (root->right->type == ELSE)
		return (execlist1(failure, fd, job, isfork));
	return (EXIT_SUCCESS);
}
