/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:27:11 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:45:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	CMPLST - CoMPound LiST
**
**        WHILE
**       /     \
** CMPLST       CMPLST
**
**        UNTIL
**       /     \
** CMPLST       CMPLST
*/

#include "execute.h"

int		execwhile(t_astree *root, int fd[2], int job, int isfork)
{
	int		res;

	res = 0;
	while (!g_execerr && execlist1(root->left, fd, job, isfork) == EXIT_SUCCESS)
		res = execlist1(root->right, fd, job, isfork);
	return (res);
}

int		execuntil(t_astree *root, int fd[2], int job, int isfork)
{
	int		res;

	res = 0;
	while (!g_execerr && execlist1(root->left, fd, job, isfork) != EXIT_SUCCESS)
		res = execlist1(root->right, fd, job, isfork);
	return (res);
}
