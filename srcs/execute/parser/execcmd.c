/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:39:04 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 19:18:21 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		execcmd(t_astree *root, int fd[2], int job, void *ppid)
{
	/* if (root->type == FUNCTION) */
	/* 	return (execfunc(root, fd, job)); */
	/* if (root->type == FOR) */
	/* 	return (execfor(root, fd, job)); */
	/* if (root->type == CASE) */
	/* 	return (execcase(root, fd, job)); */
	/* if (root->type == WHILE) */
	/* 	return (execwhile(root, fd, job)); */
	/* if (root->type == UNTIL) */
	/* 	return (execuntil(root, fd, job)); */
	/* if (root->type == SELECT) */
	/* 	return (execselect(root, fd, job)); */
	/* if (root->type == IF) */
	/* 	return (execif(root, fd, job)); */
	/* if (root->type == ARITH) */
	/* 	return (execarith(root, fd, job)); */
	/* if (root->type == COND) */
	/* 	return (execcond(root, fd, job)); */
	if (root->type == COMMAND)
		return (execscmd(root, fd, job, ppid));
	/* return (execlist1(root, fd, job, ppid)); */
	return (-228);
}
