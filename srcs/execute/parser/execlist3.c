/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execlist3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:43:35 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 14:39:36 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execlist3(t_astree *root, int fd[2], int job, int isfork)
{
#ifdef EXECUTE_DEBUG
printf("execlist3:%d\n", root->type);
#endif

	if (!root)
		return (EXIT_SUCCESS);
	if (root->type != LIST3 && root->type != AND_IF)
		return (execpipecmd(root, fd, job, isfork));
	if (!root->right)
		return (execpipecmd(root->left, fd, job, isfork));
	if (execpipecmd(root->left, fd, EX_NOFG, isfork) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (execlist3(root->right, fd, job, isfork) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
