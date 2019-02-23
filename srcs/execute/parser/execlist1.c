/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execlist1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:43:35 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 14:38:56 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execlist1(t_astree *root, int fd[2], int job, void *ppid)
{
	int		res;

	if (!root)
		return (EXIT_SUCCESS);
	/* if (job == EX_FG && root->type == LIST1) */
	/* 	return (subshell(root, fd, EX_FG)); */
	if (root->type != LIST1 && root->type != AND && root->type != SEMI &&
		root->type != NEWLINE)
		return (execlist2(root, fd, EX_NOFG, ppid));
	if (root->right && root->right->type == AND)
		res = execlist2(root->left, fd, EX_FG, ppid);
	else
		res = execlist2(root->left, fd, EX_NOFG, ppid);
	if (!root->right || !root->right->left)
		return (res);
	return (execlist1(root->right, fd, 0, ppid));
}
