/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execcase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:57:49 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 20:54:14 by bwerewol         ###   ########.fr       */
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

int		execcase(t_astree *root, int fd[2], int flag)
{
	char		*word;
	t_astree	*pattern;

	word = root->left->content;
	while ((root = root->right))
	{
		pattern = root->left;
		if (ft_strequ(word, pattern->left->content))
			return (execlist1(pattern->right, fd, flag));
	}
	return (EXIT_SUCCESS);
}
