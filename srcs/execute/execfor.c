/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execfor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 22:10:38 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:45:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	CMPLST - CoMPound LiST
**	WLST - Word LiST
**
**           FOR
**          /   \
**        IN     CMPLST
**       /
**   WORD
**
**           FOR
**          /   \
**        IN     CMPLST
**       /  \
**   WORD    WLST
*/

/*
**	WORDLIST:
**
**     \
**      WORD(content)
**          \
**           WORD(content)
**               \
**                WORD(content)
*/

/*
**	CMPLST - CoMPound LiST
**
**           FOR
**          /   \
**     ARITH     CMPLST
*/

#include "execute.h"
#include "shell.h"

static int	execarithfor(t_astree *root, int fd[2], int isfork)
{
	int			res;
	char		*arith;
	t_astree	*body;

	arith = root->left->content;
	body = root->right;
	for_first(arith);
	while (for_second(arith))
	{
		res = execlist1(body, fd, isfork);
		for_last(arith);
	}
	return (res);
}

int			execfor(t_astree *root, int fd[2], int isfork)
{
	int			res;
	char		*var;
	t_astree	*body;

	if (root->left->type == ARITH)
		return (execarithfor(root, fd, isfork));
	res = 0;
	body = root->right;
	var = root->left->left->content;
	root = root->left->right;
	while (root)
	{
		ssetenv(var, root->content, ENV_RO);
		res = execlist1(body, fd, isfork);
		root = root->right;
	}
	return (res);
}
