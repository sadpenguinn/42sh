/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpipecmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:01:57 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 19:54:14 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execpipecmd(t_astree *root, int fd[2], int flag)
{
	if (!(root) || !(root->left))
		return (-1);
	if (root->type == NOT)
		return (!execpipecmd(root->left, fd, flag));
	if (root->left->type == REST)
		return (execpipes(root->left, fd, flag));
	if (root->left->type == COMMAND)
		return (execcmd(root->left, fd, flag));
	return (-1);
}
