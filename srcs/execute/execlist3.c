/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execlist3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:43:35 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:45:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execlist3(t_astree *root, int fd[2], int isfork)
{
	if (!root)
		return (EXIT_SUCCESS);
	if (root->type != LIST3 && root->type != AND_IF)
		return (execpipecmd(root, fd, isfork));
	if (execpipecmd(root->left, fd, isfork) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (g_execerr)
		return (-1);
	if (execlist3(root->right, fd, isfork) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
