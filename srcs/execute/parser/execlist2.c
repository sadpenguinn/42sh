/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execlist2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:43:35 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 19:52:29 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execlist2(t_astree *root, int fd[2], int flag)
{
	if (root->type != LIST2 && root->type != OR_IF)
		return (execlist3(root, fd, flag));
	if (!root->right)
		return (execlist3(root->left, fd, flag));
	if (execlist3(root->left, fd, flag & ~ EX_JOB) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (execlist2(root->right, fd, flag) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
