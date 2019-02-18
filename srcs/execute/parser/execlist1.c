/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execlist1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:43:35 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 20:05:51 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execlist1(t_astree *root, int fd[2], int flag)
{
	int		res;
	int		subflag;

	if (!root)
		return (EXIT_SUCCESS);
	if (flag & EX_JOB && root->type == LIST1)
		return (subshell(root, fd, flag & ~EX_JOB));
	if (root->type != LIST1 && root->type != AND && root->type != SEMI &&
		root->type != NEWLINE)
		return (execlist2(root, fd, flag & ~EX_JOB));
	subflag = flag;
	subflag = (root->right && root->right->type == AND) ? subflag | EX_JOB :
														subflag & ~EX_JOB ;
	res = execlist2(root->left, fd, subflag);
	if (!root->right || !root->right->left)
		return (res);
	return (execlist1(root->right, fd, flag & ~EX_JOB));
}
