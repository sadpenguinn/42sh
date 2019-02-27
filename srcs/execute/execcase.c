/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execcase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:57:49 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:45:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**              CASE
**             /    \
**         WORD      IN
**                  /  \
**           PATTERN    ...
**          /       \
**      WORD         ?COMPOUND
*/

#include "execute.h"

int		execcase(t_astree *root, int fd[2], int job, int isfork)
{
	char		*word;
	t_astree	*pattern;

	word = root->left->content;
	while ((root = root->right))
	{
		pattern = root->left;
		if (ft_strequ(word, pattern->left->content))
			return (execlist1(pattern->right, fd, job, isfork));
	}
	return (EXIT_SUCCESS);
}
