/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execlist3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:43:35 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 19:53:06 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execlist3(t_astree *root, int fd[2], int flag)
{
	if (root->type != LIST3 && root->type != AND_IF)
		return (execpipecmd(root, fd, flag));
	if (!root->right)
		return (execpipecmd(root->left, fd, flag));
	if (execpipecmd(root->left, fd, flag & ~EX_JOB) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (execlist3(root->right, fd, flag) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
