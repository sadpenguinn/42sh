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

int		execlist2(t_astree *root, int fd[2], int isfork)
{
	if (!root)
		return (EXIT_FAILURE);
	if (root->type != LIST2 && root->type != OR_IF)
		return (execlist3(root, fd, isfork));
	/* if (!root->right && job) */
	/* 	return (execlist3(root->left, fd, EC_FG, isfork)); */
	if (execlist3(root->left, fd, isfork) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (g_execerr)
		return (-1);
	if (execlist2(root->right, fd, isfork) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
