/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 13:00:53 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/10 16:44:18 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**                /
**        SUBSHELL
**       /
** CMPLST
*/

#include "parser.h"

t_astree	*subshell(void)
{
	t_astree        *root;

	if (!checktype(OBRACKET))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = SUBSHELL;
	if (!(root->left = compound_list()))
		return (freeastree(root), parseerror());
	if (!checktype(CBRACKET))
		return (freeastree(root), parseerror());
	return (root);
}
