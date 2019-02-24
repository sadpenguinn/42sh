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
int res;

	if (!root)
		return (EXIT_SUCCESS);
printf("===type=== %d\n", root->type);
	if (root->type != LIST3 && root->type != AND_IF)
		return (execpipecmd(root, fd, job, isfork));
printf("===GO L3==\n");
	if (!root->right)
		return (execpipecmd(root->left, fd, job, isfork));
	if ((res = execpipecmd(root->left, fd, EX_NOFG, isfork)) != EXIT_SUCCESS)
	{
		printf(">>fail(list3; pcmd)<<res:%d\n", res);
		return (EXIT_FAILURE);
	}
	if ((res = execlist3(root->right, fd, job, isfork)) != EXIT_SUCCESS)
	{
		printf(">>fail(list3; list3->r)<<res:%d\n", res);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
