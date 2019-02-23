/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execlist2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:43:35 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 14:39:18 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execlist2(t_astree *root, int fd[2], int job, void *ppid)
{
	if (!root)
		return (EXIT_SUCCESS);
	if (root->type != LIST2 && root->type != OR_IF)
		return (execlist3(root, fd, job, ppid));
	if (!root->right)
		return (execlist3(root->left, fd, job, ppid));
	if (execlist3(root->left, fd, EX_NOFG, ppid) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (execlist2(root->right, fd, job, ppid) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
