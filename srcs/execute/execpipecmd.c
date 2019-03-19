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
	int		res;
	int		vect;

	if (!(root) || !(root->left))
		return (-1);
	vect = g_pids ? 0 : 1;
	if (vect)
		g_pids = vector_create(sizeof(pid_t));
	if (root->type == NOT)
		res = !execpipecmd(root->left, fd, isfork);
	else if (root->left->type == REST)
		res = execpipes(root->left, fd, isfork);
	else
		res = execcmd(root->left, fd, isfork);
	if (vect)
		vector_free(&g_pids);
	return (res);
}
