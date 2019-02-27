/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execlist2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:43:35 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:45:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execlist2(t_astree *root, int fd[2], int job, int isfork)
{
	if (!root)
		return (EXIT_SUCCESS);
	if (root->type != LIST2 && root->type != OR_IF)
		return (execlist3(root, fd, job, isfork));
	if (!root->right)
		return (execlist3(root->left, fd, job, isfork));
	if (execlist3(root->left, fd, EX_NOFG, isfork) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (execlist2(root->right, fd, job, isfork) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
