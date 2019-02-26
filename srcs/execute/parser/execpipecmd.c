/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpipecmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:01:57 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 13:41:56 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execpipecmd(t_astree *root, int fd[2], int flag, int isfork)
{
#ifdef EXECUTE_DEBUG
printf("execpipecmd:%d\n", root->type);
#endif
	if (!(root) || !(root->left))
		return (-1);
	if (root->type == NOT)
		return (!execpipecmd(root->left, fd, flag, isfork));
	if (root->left->type == REST)
		return (execpipes(root->left, fd, flag, isfork));
	execcmd(root->left, fd, flag, 0);
	printf(">COMMAND OK<\n");
	return (1);
}
