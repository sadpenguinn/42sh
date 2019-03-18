/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpipecmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:01:57 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:45:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execpipecmd(t_astree *root, int fd[2], int isfork)
{
	if (!(root) || !(root->left))
		return (-1);
	if (root->type == NOT)
		return (!execpipecmd(root->left, fd, isfork));
	if (root->left->type == REST)
		return (execpipes(root->left, fd, isfork));
	return (execcmd(root->left, fd, 0));
}
